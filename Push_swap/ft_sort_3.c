/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:10:44 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/04 18:30:43 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	check_if_sorted(t_stack **a_stack)
{
	t_stack	*tmp;

	tmp = *a_stack;
	while (tmp && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr && tmp->next)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_three(t_stack **a_stack, int fd)
{
	int		sorted;

	sorted = check_if_sorted(a_stack);
	while (sorted != 1)
	{
		if ((*a_stack)->next->nbr < (*a_stack)->nbr)
			ft_sa_pre(a_stack, fd);
		else if ((*a_stack)->next->nbr > (*a_stack)->nbr)
			ft_rra_pre(a_stack, fd);
		sorted = check_if_sorted(a_stack);
	}
	return ;
}

void	ft_sort_5(t_stack **a_stack, t_stack **b_stack, int fd)
{
	int		i;
	int		sorted;

	sorted = check_if_sorted(a_stack);
	i = 0;
	if (sorted == 0)
	{
		ft_pb(a_stack, b_stack, fd);
		ft_pb(a_stack, b_stack, fd);
		if ((*b_stack)->nbr > (*b_stack)->next->nbr)
			ft_sb(b_stack, fd);
		ft_sort_three(a_stack, fd);
		while (*b_stack)
		{
			i = place_to_put(a_stack, (*b_stack)->nbr);
			if (i == 0)
				ft_pa_pre(a_stack, b_stack, fd);
			else if (i > 0)
			{
				while (i-- > 0)
					ft_ra_pre(a_stack, fd);
				ft_pa_pre(a_stack, b_stack, fd);
			}
			else if (i < 0)
			{
				while (i++ < 0)
					ft_rra_pre(a_stack, fd);
				ft_pa_pre(a_stack, b_stack, fd);
			}
			sorted = check_if_sorted(a_stack);
		}
	}
}

int	place_to_put(t_stack **a_stack, int nbr)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a_stack;
	while (tmp)
	{
		if (nbr <= tmp->nbr && (tmp->prev == NULL || nbr >= tmp->prev->nbr))
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}
