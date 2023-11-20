
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

GET_NEXT_LINE_DIR = ./get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a

SRCS = ft_printf.c \
      ft_printf_utils.c \
	  ft_putnbr_base.c \
	  ft_unsigned_itoa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(LIBFT) $(GET_NEXT_LINE) $(OBJS) 
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)
$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(GET_NEXT_LINE_DIR) -c $< -o $@
$(LIBFT): 
	make all bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
$(GET_NEXT_LINE):
	make all -C $(GET_NEXT_LINE_DIR)
	cp $(GET_NEXT_LINE) $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: NAME all clean fclean re
