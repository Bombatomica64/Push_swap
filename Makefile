# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:05:48 by lmicheli          #+#    #+#              #
#    Updated: 2023/12/04 17:58:19 by lmicheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc -Wall -Wextra -Werror

SRC = Push_swap.c ft_check_stack.c ft_make_list.c ft_matrix_size.c ft_mtoi.c \
	  ft_push.c misc.c move.c reverse_spin.c spin.c ft_sort_3.c

BONUS_SRC = checker/checker.c


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