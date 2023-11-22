/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:10:44 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/22 16:23:40 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	check_if_sorted(t_stack_node **a_stack)
{
	int				i;
	t_stack_node	*tmp;

	i = 0;
	tmp = *a_stack;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_three(t_stack_node **a_stack, int size)
{
	int		i;
	int		sorted;

	sorted = 0;
	i = 0;
	while (!sorted)
	{
		if ((*a_stack)->next->nbr > (*a_stack)->nbr)
			ft_sa(a_stack);
		else if ((*a_stack)->next->nbr < (*a_stack)->nbr)
			ft_rra(a_stack);
		
	}
}
