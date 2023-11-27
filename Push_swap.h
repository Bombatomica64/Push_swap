/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:58:05 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/27 12:08:38 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int				nbr;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}		t_stack_node;

/* typedef struct s_leonardo
{
	int			p;
	int			r;
	int			q;
}	t_leonardo; */

int				ft_check_stack(char **array);
int				ft_max(int a, int b);
int				ft_check_for_non_int(char *str);
int				*ft_mtoi(char **array);
int				ft_matrix_len(char **array);
void			ft_sort(int *stack_a, int *stack_b, int size);
void			ft_free_matrix(char **array);
void			check_for_dupes(int *stack, int size);
t_stack_node	*ft_stack_node_new(int nbr);
t_stack_node	*ft_make_list(int *stack, int size);
t_stack_node	*ft_node_last(t_stack_node *stack);
t_stack_node	*ft_node_first(t_stack_node *stack);
void			ft_node_add_back(t_stack_node **stack, t_stack_node *new_node);
void			ft_node_add_front(t_stack_node **stack, t_stack_node *new_node);
void			ft_sort_three(t_stack_node **a_stack);
void			ft_sort_5(t_stack_node **a_stack);
void			ft_sa_pre(t_stack_node **stack_a);
void			ft_sa(t_stack_node **stack_a);
void			ft_sb(t_stack_node **stack_b);
void			ft_ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			ft_pa_pre(t_stack_node **stack_a, t_stack_node **stack_b);
void			ft_pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			ft_pb(t_stack_node **stack_a, t_stack_node **stack_b);
void			ft_ra_pre(t_stack_node **stack_a);
void			ft_ra(t_stack_node **stack_a);
void			ft_rb(t_stack_node **stack_b);
void			ft_rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			ft_rra_pre(t_stack_node **stack_a);
void			ft_rra(t_stack_node **stack_a);
void			ft_rrb(t_stack_node **stack_b);
void			ft_rrr(t_stack_node **stack_a, t_stack_node **stack_b);

#endif
