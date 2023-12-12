/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:09:35 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/12 11:46:14 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_index_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;
	int		index;
	long	current_min;

	index = 0;
	tmp = *stack;
	head = *stack;
	current_min = -2147483649;
	while (index < ft_list_size(*stack))
	{
		current_min = ft_next_min(&head, current_min);
		tmp = *stack;
		while (tmp)
		{
			if (tmp->nbr == current_min)
			{
				tmp->index = index;
				index++;
				break ;
			}
			tmp = tmp->next;
		}
	}
}

int	ft_next_min(t_stack **stack, long min)
{
	long		next_min;
	t_stack		*tmp;

	tmp = *stack;
	next_min = 2147483647;
	while (tmp)
	{
		if (tmp->nbr < next_min && tmp->nbr > min)
			next_min = tmp->nbr;
		tmp = tmp->next;
	}
	return (next_min);
}
