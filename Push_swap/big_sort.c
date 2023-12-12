/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:07:03 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/12 10:52:27 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_big_radix_sort(t_stack **a_stack, t_stack **b_stack)
{
	int		shift;

	shift = 0;
	while (shift < ft_index_max(a_stack))
	{
		while ((*a_stack)->next)
		{
			if ((((*a_stack)->index >> shift) & 1) == 1)
				ft_ra_pre(a_stack, 1);
			else
				ft_pb(a_stack, b_stack, 1);
		}
		while (*b_stack)
			ft_pa_pre(a_stack, b_stack, 1);
		shift++;
	}
}

int	ft_index_max(t_stack **a_stack)
{
	int		max;
	int		max_len;
	t_stack	*tmp;

	max = 0;
	max_len = 0;
	tmp = *a_stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while (max)
	{
		max >>= 1;
		max_len++;
	}
	return (max_len);
}
