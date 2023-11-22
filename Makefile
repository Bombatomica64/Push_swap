# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:05:48 by lmicheli          #+#    #+#              #
#    Updated: 2023/11/22 17:37:51 by lmicheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc -Wall -Wextra -Werror

SRC = Push_swap.c ft_check_stack.c ft_make_list.c ft_matrix_size.c ft_mtoi.c \
	  ft_push.c ft_misc.c ft_move.c ft_reverse_spin.c ft_spin.c

OBJ = $(SRC:.c=.o)

FT_PRINTF = ft_printf

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $?
	$(MAKE) -C $(FT_PRINTF)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FT_PRINTF) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF) fclean

re: fclean all
	$(MAKE) -C $(FT_PRINTF) re

.PHONY: all clean fclean bonus re