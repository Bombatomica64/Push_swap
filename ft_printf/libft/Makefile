# Name of the executable #
NAME = libft.a

# Source files and object files #
SRC = ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
ft_atoi.c  ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c \
ft_isalnum.c ft_memcpy.c ft_strchr.c ft_strncmp.c \
ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c \
ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c \
ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_itoa.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Compiler and compiler flags #

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Targets #
all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $@ $?
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)
bonus: $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
