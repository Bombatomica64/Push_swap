/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:35:30 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/15 15:58:22 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_rra_pre(t_stack **a_stack, int fd)
{
	ft_rra(a_stack);
	write(fd, "rra\n", 4);
}

void	ft_rra(t_stack **a_stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = (*a_stack);
	while (tmp->next)
		tmp = tmp->next;
	last = tmp;
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = (*a_stack);
	(*a_stack)->prev = last;
	(*a_stack) = last;
}

void	ft_rrb(t_stack **stack_b, int fd)
{
	ft_rra(stack_b);
	write(fd, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int fd)
{
	ft_rra(stack_a);
	ft_rra(stack_b);
	write(fd, "rrr\n", 5);
}
