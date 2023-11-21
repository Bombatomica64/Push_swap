/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:58:05 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/20 18:43:43 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int				nbr;
	struct s_list	*prev;
	struct s_list	*next;
}		t_stack_node;

int				ft_check_stack(char **array);
int				ft_min(int a, int b);
int				ft_check_for_non_int(char *str);
int				*ft_mtoi(char **array);
int				ft_matrix_len(char **array);
void			ft_sort(int *stack_a, int *stack_b, int size);
void			ft_free_matrix(char **array);
t_stack_node	*ft_stack_node_new(int nbr);
t_stack_node	*ft_make_list(int *stack, int size);
void			ft_node_add_back(t_stack_node **stack, t_stack_node *new_node);

#endif