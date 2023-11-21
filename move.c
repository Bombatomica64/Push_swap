/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:35:36 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/21 17:15:55 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_sa(t_stack_node **a_stack)
{
	t_stack_node	*tmp;

	if (!(*a_stack) || !(*a_stack)->next)
		return ;
	tmp = *a_stack;
	*a_stack = (*a_stack)->next;
	tmp->next = (*a_stack)->next;
	(*a_stack)->next = tmp;
	(*a_stack)->prev = NULL;
	tmp->prev = *a_stack;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack_node **b_stack)
{
	ft_sa(b_stack);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack_node **a_stack, t_stack_node **b_stack)
{
	ft_sa(a_stack);
	ft_sa(b_stack);
	write(1, "ss\n", 3);
}

void	ft_pa(t_stack_node **a_stack, t_stack_node **b_stack)
{
	if (!(*b_stack) || !(*b_stack)->next)
		return ;
	(*b_stack)->next->prev = NULL;
	ft_node_add_front(a_stack, *b_stack);
	*b_stack = (*b_stack)->next;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack_node **a_stack, t_stack_node **b_stack)
{
	if (!(*a_stack) || !(*a_stack)->next)
		return ;
	ft_pa(b_stack, a_stack);
	write(1, "pb\n", 3);
}
