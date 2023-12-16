/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:10:44 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/14 10:56:23 by lmicheli         ###   ########.fr       */
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

	i = 0;
	if (check_if_sorted(a_stack) == 0)
	{
		ft_pb(a_stack, b_stack, fd);
		ft_pb(a_stack, b_stack, fd);
		if ((*b_stack)->nbr > (*b_stack)->next->nbr)
			ft_sb(b_stack, fd);
		ft_sort_three(a_stack, fd);
		while (ft_list_size(*a_stack) < 5)
		{
			i = place_to_put(a_stack, (*b_stack)->index);
			if (i == 0)
				ft_pa_pre(a_stack, b_stack, 1);
			else if (i > 0)
				ft_ra_pre(a_stack, 1);
			else if (i < 0)
				ft_rra_pre(a_stack, 1);
			if (ft_list_size(*a_stack) == 5)
				break ;
		}
		while (check_if_sorted(a_stack) == 0)
			ft_ra_pre(a_stack, 1);
	}
}

int	place_to_put(t_stack **a_stack, int index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *a_stack;
	while (head)
	{
		if (head->index == (index + 1))
			break ;
		distance++;
		head = head->next;
	}
	if (distance > ft_list_size(*a_stack) / 2)
		distance = distance - ft_list_size(*a_stack);
	return (distance);
}
