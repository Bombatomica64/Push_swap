/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:58:05 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/12 11:08:22 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int						nbr;
	int						index;
	struct s_stack_node		*prev;
	struct s_stack_node		*next;
}		t_stack;

int				ft_check_stack(char **array);
int				ft_max(int a, int b);
int				ft_check_for_non_int(char *str);
int				*ft_mtoi(char **array);
int				ft_matrix_len(char **array);
int				check_if_sorted(t_stack **a_stack);
int				ft_list_size(t_stack *stack);
int				place_to_put(t_stack **a_stack, int nbr);
int				ft_next_min(t_stack **stack, long min);
int				ft_index_max(t_stack **a_stack);
void			ft_sort(int *stack_a, int *stack_b, int size, int fd);
void			ft_free_matrix(char **array);
void			check_for_dupes(int *stack, int size);
t_stack			*ft_stack_node_new(int nbr);
t_stack			*ft_make_list(int *stack, int size);
t_stack			*lst_lst(t_stack *stack);
t_stack			*ft_node_first(t_stack *stack);
void			ft_node_add_back(t_stack **stack, t_stack *new_node);
void			ft_node_add_front(t_stack **stack, t_stack *new_node);
void			ft_sort_three(t_stack **a_stack, int fd);
void			ft_sort_5(t_stack **a_stack, t_stack **b_stack, int fd);
void			ft_sa_pre(t_stack **stack_a, int fd);
void			ft_sa(t_stack **stack_a);
void			ft_sb(t_stack **stack_b, int fd);
void			ft_ss(t_stack **stack_a, t_stack **stack_b, int fd);
void			ft_pa_pre(t_stack **stack_a, t_stack **stack_b, int fd);
void			ft_pa(t_stack **stack_to, t_stack **stack_from);
void			ft_pb(t_stack **stack_a, t_stack **stack_b, int fd);
void			ft_ra_pre(t_stack **stack_a, int fd);
void			ft_ra(t_stack **stack_a);
void			ft_rb(t_stack **stack_b, int fd);
void			ft_rr(t_stack **stack_a, t_stack **stack_b, int fd);
void			ft_rra_pre(t_stack **stack_a, int fd);
void			ft_rra(t_stack **a_stack);
void			ft_rrb(t_stack **stack_b, int fd);
void			ft_rrr(t_stack **stack_a, t_stack **stack_b, int fd);
void			ft_print_stack(t_stack *stack);
void			ft_error(void);
void			ft_ko(void);
void			ft_ok(void);
void			ft_index_stack(t_stack **a_stack);
void			ft_big_radix_sort(t_stack **a_stack, t_stack **b_stack);
void			ft_print_index(t_stack *stack);

#endif
