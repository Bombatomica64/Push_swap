/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:29:58 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/05 16:11:33 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_checker.h"

void	ft_pa_no_print(t_stack **stack_to, t_stack **stack_from)
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

void	ft_pb_no_print(t_stack **a_stack, t_stack **b_stack)
{
	ft_pa_no_print(b_stack, a_stack);
}

void	ft_sa_no_print(t_stack **a_stack)
{
	t_stack	*tmp;

	if (!(*a_stack) || !(*a_stack)->next)
		return ;
	tmp = *a_stack;
	*a_stack = (*a_stack)->next;
	tmp->next = (*a_stack)->next;
	(*a_stack)->next = tmp;
	(*a_stack)->prev = NULL;
	tmp->prev = *a_stack;
}

void	ft_sb_no_print(t_stack **b_stack)
{
	ft_sa_no_print(b_stack);
}

void	ft_ss_no_print(t_stack **a_stack, t_stack **b_stack)
{
	ft_sa_no_print(a_stack);
	ft_sa_no_print(b_stack);
}
