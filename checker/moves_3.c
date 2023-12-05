/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:16:51 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/05 16:18:30 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_checker.h"

void	ft_rra_no_print(t_stack **a_stack)
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

void	ft_rrb_no_print(t_stack **b_stack)
{
	ft_rra_no_print(b_stack);
}

void	ft_rrr_no_print(t_stack **a_stack, t_stack **b_stack)
{
	ft_rra_no_print(a_stack);
	ft_rra_no_print(b_stack);
}
