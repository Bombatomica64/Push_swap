/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:16:51 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/15 15:58:46 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_checker.h"

void	ft_rra_no_print(t_stack **a_stack)
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

void	ft_rrb_no_print(t_stack **b_stack)
{
	ft_rra_no_print(b_stack);
}

void	ft_rrr_no_print(t_stack **a_stack, t_stack **b_stack)
{
	ft_rra_no_print(a_stack);
	ft_rra_no_print(b_stack);
}
