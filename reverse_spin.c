/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_spin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:43:04 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/30 10:24:26 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_ra_pre(t_stack **a_stack, int fd)
{
	ft_ra(a_stack);
	write(fd, "ra\n", 4);
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	while (temp->next)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	ft_rb(t_stack **stack_b, int fd)
{
	ft_ra(stack_b);
	write(fd, "rb\n", 4);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int fd)
{
	ft_ra(stack_a);
	ft_ra(stack_b);
	write(fd, "rr\n", 3);
}
// Compare this snippet from ft_make_list.c: