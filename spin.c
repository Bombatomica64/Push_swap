/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:35:30 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/29 17:41:03 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_rra_pre(t_stack **a_stack, int fd)
{
	ft_ra(a_stack);
	write(fd, "rra\n", 4);
}

void	ft_rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

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
