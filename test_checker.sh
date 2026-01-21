#!/usr/bin/env bash
set -euo pipefail

# Simple push_swap test runner for zsh users:
# Runs push_swap with a generated permutation and validates with the 42 checker.

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PUSH_SWAP="$ROOT_DIR/push_swap"
CHECKER=""

usage() {
  cat <<'EOF'
Usage:
  bash test_checker.sh [options]

Options:
  -c, --checker PATH    Path to checker_OS binary (default: auto-detect)
  -n, --size N         Number of values (default: 100)
  -i, --iters N        How many random tests to run (default: 20)
  -s, --seed N         Seed for shuf (optional, GNU shuf)
  -q, --quiet          Only print failures
  --show-ops           Print operations when KO (first 80 lines)
  -h, --help           Show help

Examples:
  bash test_checker.sh                 # 20 tests, N=100
  bash test_checker.sh -n 500 -i 5     # 5 tests, N=500
EOF
}

SIZE=100
ITERS=20
SEED=""
QUIET=0
SHOW_OPS=0

while [[ $# -gt 0 ]]; do
  case "$1" in
    -c|--checker) CHECKER="$2"; shift 2;;
    -n|--size) SIZE="$2"; shift 2;;
    -i|--iters) ITERS="$2"; shift 2;;
    -s|--seed) SEED="$2"; shift 2;;
    -q|--quiet) QUIET=1; shift;;
    --show-ops) SHOW_OPS=1; shift;;
    -h|--help) usage; exit 0;;
    *) echo "Unknown arg: $1"; usage; exit 2;;
  esac
done

if [[ ! -x "$PUSH_SWAP" ]]; then
  echo "push_swap not found; running make..." >&2
  make -C "$ROOT_DIR" >/dev/null
fi

if [[ ! -x "$PUSH_SWAP" ]]; then
  echo "Error: push_swap not found/executable at: $PUSH_SWAP" >&2
  echo "Build failed or binary not generated. Try: make" >&2
  exit 1
fi

if [[ -z "$CHECKER" ]]; then
  if [[ -x "$ROOT_DIR/checker_OS/checker_OS" ]]; then
    CHECKER="$ROOT_DIR/checker_OS/checker_OS"
  elif [[ -x "$ROOT_DIR/checker_OS/checker_linux" ]]; then
    CHECKER="$ROOT_DIR/checker_OS/checker_linux"
  elif command -v checker_OS >/dev/null 2>&1; then
    CHECKER="$(command -v checker_OS)"
  fi
fi

if [[ -z "$CHECKER" || ! -x "$CHECKER" ]]; then
  echo "Error: checker_OS not found/executable." >&2
  echo "Looked for: checker_OS/checker_linux, checker_OS/checker_OS, checker_OS in PATH" >&2
  echo "Provide manually with: bash test_checker.sh --checker /path/to/checker_OS" >&2
  exit 1
fi

if ! command -v shuf >/dev/null 2>&1; then
  echo "Error: 'shuf' not found. Install coreutils (e.g. sudo apt-get install coreutils)." >&2
  exit 1
fi

pass=0
fail=0

mk_case() {
  local n="$1"
  if [[ -n "$SEED" ]]; then
    # GNU shuf supports --random-source but not a numeric seed.
    # We emulate a seed using openssl/printf only if available; otherwise ignore seed.
    if command -v openssl >/dev/null 2>&1; then
      seq 1 "$n" | shuf --random-source=<(openssl enc -aes-256-ctr -pass pass:"$SEED" -nosalt </dev/zero 2>/dev/null)
    else
      seq 1 "$n" | shuf
    fi
  else
    seq 1 "$n" | shuf
  fi
}

for ((t=1; t<=ITERS; t++)); do
  mapfile -t arr < <(mk_case "$SIZE")

  ops_file="$(mktemp)"
  err_file="$(mktemp)"
  # Generate operations
  "$PUSH_SWAP" "${arr[@]}" >"$ops_file" 2>"$err_file" || true

  if [[ -s "$err_file" ]]; then
    fail=$((fail+1))
    echo "[$t/$ITERS] ERROR (push_swap wrote to stderr)" >&2
    echo "ARGS: ${arr[*]}" >&2
    cat "$err_file" >&2
    rm -f "$ops_file" "$err_file"
    continue
  fi

  # Validate
  result=$(cat "$ops_file" | "$CHECKER" "${arr[@]}" 2>/dev/null | tr -d '\r' | tail -n 1)
  ops_count=$(wc -l < "$ops_file" | tr -d ' ')

  if [[ "$result" == "OK" ]]; then
    pass=$((pass+1))
    [[ "$QUIET" -eq 1 ]] || echo "[$t/$ITERS] OK  (n=$SIZE ops=$ops_count)"
  else
    fail=$((fail+1))
    echo "[$t/$ITERS] KO  (n=$SIZE ops=$ops_count)" >&2
    echo "ARGS: ${arr[*]}" >&2
    if [[ "$SHOW_OPS" -eq 1 ]]; then
      echo "--- ops (first 80) ---" >&2
      head -n 80 "$ops_file" >&2
      echo "---" >&2
    fi
    # Keep the failing ops for inspection
    cp "$ops_file" "$ROOT_DIR/last_ko_ops.txt" || true
    echo "Saved ops to: $ROOT_DIR/last_ko_ops.txt" >&2
  fi

  rm -f "$ops_file" "$err_file"

done

echo "Done. PASS=$pass FAIL=$fail (n=$SIZE iters=$ITERS)"

if [[ "$fail" -gt 0 ]]; then
  exit 3
fi
