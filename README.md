*This project has been created as part of the 42 curriculum by sdelmond.*

## Description
`push_swap` is an algorithmic project where you must sort a list of unique integers using **two stacks** (`a` and `b`) and a limited set of operations (`sa`, `pb`, `ra`, etc.).

The program prints, to standard output, a sequence of instructions that sorts stack `a` in ascending order while trying to minimize the number of operations.

## Instructions
### Build
- `make`

### Run
- Example:
  - `./push_swap 2 1 3 6 5 8`

### Behavior requirements (from the subject)
- With **no arguments**, the program prints nothing.
- On **invalid input** (non-integers, duplicates, overflow), it prints `Error` followed by a newline on **stderr**.

### Clean
- `make clean` removes object files.
- `make fclean` removes objects and the `push_swap` binary.
- `make re` rebuilds from scratch.

## Resources
- 42 subject: `en.subject.pdf`
- Stack-based sorting / push_swap references:
  - youtube.com
  - Ai for sugestion algorithms

### AI usage
I used GitHub Copilot to:
- iterate on the Makefile structure (targets, object directory, incremental rebuild)
- write supporting project documentation

All generated suggestions were reviewed and adapted manually.
