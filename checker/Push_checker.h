/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_checker.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:28:52 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/07 16:13:10 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_CHECKER_H
# define PUSH_CHECKER_H

# include "../Push_swap/ft_printf/libft.h"
# include "../Push_swap/ft_printf/ft_printf.h"
# include "../Push_swap/Push_swap.h"
# include "../Push_swap/ft_printf/get_next_line_bonus.h"

void	ft_check_moves(int *stack_a, int *stack_b, int size);
void	ft_pa_no_print(t_stack **a_stack, t_stack **b_stack);
void	ft_pb_no_print(t_stack **a_stack, t_stack **b_stack);
void	ft_sa_no_print(t_stack **a_stack);
void	ft_sb_no_print(t_stack **b_stack);
void	ft_ss_no_print(t_stack **a_stack, t_stack **b_stack);
void	ft_ra_no_print(t_stack **a_stack);
void	ft_rb_no_print(t_stack **b_stack);
void	ft_rr_no_print(t_stack **a_stack, t_stack **b_stack);
void	ft_rra_no_print(t_stack **a_stack);
void	ft_rrb_no_print(t_stack **b_stack);
void	ft_rrr_no_print(t_stack **a_stack, t_stack **b_stack);
void	ft_error(void);
void	ft_ko(void);
void	ft_ok(void);
char	*check_sorting_status(int sorted, t_stack *b_stack, int read_bytes);

#endif