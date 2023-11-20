# Name of the executable #
NAME = get_next_line.a

# Source files and object files #
SRC = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

# Compiler and compiler flags #

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Targets #
all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $@ $^
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean bonus re
