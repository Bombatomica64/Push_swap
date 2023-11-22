/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_spin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:43:04 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/22 16:45:22 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_rra_pre(t_stack_node **a_stack)
{
	ft_rra(a_stack);
	write(1, "rra\n", 4);
}

void	ft_rra(t_stack_node **stack_a)
{
	t_stack_node	*temp;
	t_stack_node	*last;

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

void	ft_rrb(t_stack_node **stack_b)
{
	ft_rra(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	write(1, "rrr\n", 4);
}
// Compare this snippet from ft_make_list.c: