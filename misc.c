/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:16:11 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/22 16:05:13 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	make_lists(int *stack_a, int *stack_b, int size)
{
	int				i;
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;

	a_stack = ft_make_list(stack_a, size);
	b_stack = ft_make_list(stack_b, size);
}

int	*ft_array_dup(int *stack_a, int size)
{
	int	i;
	int	*dup;

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
