/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:35:36 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/29 17:14:32 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_sa_pre(t_stack **a_stack, int fd)
{
	ft_sa(a_stack);
	write(fd, "sa\n", 3);
}

void	ft_sa(t_stack **a_stack)
{
	t_stack	*tmp;

	if (!(*a_stack) || !(*a_stack)->next)
		return ;
	tmp = *a_stack;
	*a_stack = (*a_stack)->next;
	tmp->next = (*a_stack)->next;
	(*a_stack)->next = tmp;
	(*a_stack)->prev = NULL;
	tmp->prev = *a_stack;
}

void	ft_sb(t_stack **b_stack, int fd)
{
	ft_sa(b_stack);
	write(fd, "sb\n", 3);
}

void	ft_ss(t_stack **a_stack, t_stack **b_stack, int fd)
{
	ft_sa(a_stack);
	ft_sa(b_stack);
	write(fd, "ss\n", 3);
}
