/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:41:37 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/30 12:35:37 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_pa_pre(t_stack **a_stack, t_stack **b_stack, int fd)
{
	ft_pa(a_stack, b_stack);
	write(fd, "pa\n", 3);
}

/* void	ft_pa(t_stack_node **a_stack, t_stack_node **b_stack)
{
	t_stack_node	*tmp;
	t_stack_node	*head_to;
	t_stack_node	*head_from;

	if (!*a_stack)
		return ;
	head_to = *b_stack;
	head_from = *a_stack;
	tmp = head_from;
	head_from = head_from->next;
	*a_stack = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		head_to->prev = NULL;
		*b_stack = head_to;
	}
	else
	{
		tmp->next = head_to;
		tmp->prev = NULL;
		head_to->prev = tmp;
		*b_stack = tmp;
	}
} */

void	ft_pa(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;
	t_stack	*head_to;
	t_stack	*head_from;

	if (ft_list_size(*stack_from) == 0)
		return ;
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
}

void	ft_pb(t_stack **a_stack, t_stack **b_stack, int fd)
{
	if (!(*a_stack) || !(*a_stack)->next)
		return ;
	ft_pa(b_stack, a_stack);
	write(fd, "pb\n", 3);
}

void	ft_node_add_front(t_stack **stack, t_stack *new)
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
