/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:35:30 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/05 16:21:49 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_rra_pre(t_stack **a_stack, int fd)
{
	ft_ra(a_stack);
	write(fd, "rra\n", 4);
}

void	ft_rra(t_stack **a_stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*a_stack) || !(*a_stack)->next)
		return ;
	tmp = *a_stack;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *a_stack;
	*a_stack = tmp;
}

void	ft_rrb(t_stack **stack_b, int fd)
{
	ft_ra(stack_b);
	write(fd, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int fd)
{
	ft_rra(stack_a);
	ft_rra(stack_b);
	write(fd, "rrr\n", 5);
}
