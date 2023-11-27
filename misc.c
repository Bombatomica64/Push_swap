/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:16:11 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/27 11:24:03 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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
