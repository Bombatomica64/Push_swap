/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_spin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:43:04 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/15 18:11:34 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_ra_pre(t_stack **a_stack, int fd)
{
	if (!(*a_stack) || !(*a_stack)->next)
		return ;
	ft_ra(a_stack);
	write(fd, "ra\n", 3);
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	first = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->next->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->prev = tmp;
	first->next = NULL;
}

void	ft_rb(t_stack **stack_b, int fd)
{
	ft_ra(stack_b);
	write(fd, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int fd)
{
	ft_ra(stack_a);
	ft_ra(stack_b);
	write(fd, "rr\n", 3);
}
