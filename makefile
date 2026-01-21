NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror
INCS	:= -I ./headers/
RM := rm -f

SRC_DIR := src
OBJ_DIR := obj


SRC = main.c \
		aux/find_and_check.c \
		aux/parse_data.c \
		aux/utils.c \
		moves/push.c \
		moves/reverse_rotate.c \
		moves/rotate.c \
		moves/swap.c \
		sort/sort_small.c \
		sort/sort_large.c \
		sort/sort_large_utils.c \
		sort/sort.c


OBJ		= $(SRC:.c=.o)

SRCS := $(addprefix $(SRC_DIR)/, $(SRC))
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))


all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
