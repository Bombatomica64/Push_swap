/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:12:24 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/15 15:16:04 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_checker.h"

void	ft_ra_no_print(t_stack **a_stack)
{
	t_stack	*tmp;
	t_stack	*first;

	tmp = (*a_stack);
	first = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	(*a_stack)->next->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->prev = tmp;
	first->next = NULL;
}

void	ft_rb_no_print(t_stack **b_stack)
{
	ft_ra_no_print(b_stack);
}

void	ft_rr_no_print(t_stack **a_stack, t_stack **b_stack)
{
	ft_ra_no_print(a_stack);
	ft_ra_no_print(b_stack);
}
