/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:57:56 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/20 17:01:34 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	*ft_mtoi(char **array)
{
	int	*stack;
	int	i;

	i = 0;
	while (array[i])
		i++;
	stack = malloc(sizeof(int) * i);
	i = 0;
	while (array[i])
	{
		stack[i] = ft_atoi(array[i]);
		i++;
	}
	return (stack);
}
// Path: ft_mtoi.c
// Compare this snippet from Push_swap.h: