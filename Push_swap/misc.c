/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:16:11 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/03 16:12:49 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	*ft_array_dup(int *stack_a, int size)
{
	int		i;
	int		*dup;

	i = 0;
	dup = malloc(sizeof(int) * size);
	if (!dup)
		return (NULL);
	while (i < size)
	{
		dup[i] = stack_a[i];
		i++;
	}
	return (dup);
}

int	ft_list_size(t_stack *stack)
{
	int				i;
	t_stack			*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*lst_lst(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
