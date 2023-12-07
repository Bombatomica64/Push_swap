# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:05:48 by lmicheli          #+#    #+#              #
#    Updated: 2023/12/07 17:27:14 by lmicheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker


CC = cc -Wall -Wextra -Werror

SRC = Push_swap.c ft_check_stack.c ft_make_list.c ft_matrix_size.c ft_mtoi.c \
	  ft_push.c misc.c move.c reverse_spin.c spin.c ft_sort_3.c

BONUS_SRC = ../checker/checker.c ../checker/moves_1.c ../checker/moves_2.c \
			../checker/moves_3.c ../checker/ending.c \
			ft_check_stack.c ft_make_list.c ft_matrix_size.c ft_mtoi.c \
	  		ft_push.c misc.c move.c reverse_spin.c spin.c ft_sort_3.c


OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

FT_PRINTF = ft_printf

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	make all -C $(FT_PRINTF)
	$(CC) $(OBJ) ft_printf/libftprintf.a -o $@

$(BONUS_NAME): $(BONUS_OBJ)
	make all -C $(FT_PRINTF)
	$(CC) $(BONUS_OBJ) ft_printf/libftprintf.a -o $(BONUS_NAME)

%.o: %.c
	$(CC) -c $< -o $@

both: all bonus

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make clean -C $(FT_PRINTF)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make fclean -C $(FT_PRINTF)
	
re: fclean both
	make re -C $(FT_PRINTF)

.PHONY: all both clean fclean bonus re