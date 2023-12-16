/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:07:03 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/16 12:33:11 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_big_radix_sort(t_stack **a_stack, t_stack **b_stack)
{
	int		shift;
	int		i;
	int		size;
	int		max_len;

	i = 0;
	shift = 0;
	size = ft_list_size(*a_stack);
	max_len = ft_index_max(a_stack);
	if (check_if_sorted(a_stack))
		return ;
	while (shift++ < max_len)
	{
		i = 0;
		while (i++ < size)
		{
			if ((((*a_stack)->index >> shift) & 1) == 1)
				ft_ra_pre(a_stack, 1);
			else
				ft_pb(a_stack, b_stack, 1);
		}
		while (ft_list_size(*a_stack) < size)
			ft_pa_pre(a_stack, b_stack, 1);
			//sesso
	}
}

int	ft_index_max(t_stack **a_stack)
{
	int		max;
	int		max_len;
	t_stack	*tmp;

	max = -20;
	max_len = 0;
	tmp = *a_stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while (max != 0)
	{
		max >>= 1;
		max_len++;
	}
	return (max_len);
}
