/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:41:37 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/27 11:43:31 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_pa_pre(t_stack_node **a_stack, t_stack_node **b_stack)
{
	ft_pa(a_stack, b_stack);
	write(1, "pa\n", 3);
}

void	ft_pa(t_stack_node **a_stack, t_stack_node **b_stack)
{
	if (!(*b_stack) || !(*b_stack)->next)
		return ;
	(*b_stack)->next->prev = NULL;
	ft_node_add_front(a_stack, *b_stack);
	*b_stack = (*b_stack)->next;
}

void	ft_pb(t_stack_node **a_stack, t_stack_node **b_stack)
{
	if (!(*a_stack) || !(*a_stack)->next)
		return ;
	ft_pa(b_stack, a_stack);
	write(1, "pb\n", 3);
}
void	ft_node_add_front(t_stack_node **stack, t_stack_node *new)
{
	if (!new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
