/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:35:30 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/22 16:44:47 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_ra_pre(t_stack_node **a_stack)
{
	ft_ra(a_stack);
	write(1, "ra\n", 3);
}

void	ft_ra(t_stack_node **stack_a)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
}

void	ft_rb(t_stack_node **stack_b)
{
	ft_ra(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	write(1, "rr\n", 3);
}
