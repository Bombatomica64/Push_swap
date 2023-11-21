/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:43:29 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/20 18:07:10 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_free_matrix(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_check_stack(char **array)
{
	int		i;
	int		*temp;
	int		j;
	int		min;

	i = 0;
	while (array[i])
	{
		temp = array[i];
		j = i;
		while (array[j])
		{
			min = ft_min(ft_strlen(temp), ft_strlen(array[j]));
			if (ft_strncmp(temp, array[j++], min) == 0)
			{
				write (2, "Error\n", 6);
				ft_free_matrix(array);
				free(temp);
				exit(0);
			}
		}
		i++;
	}
	free(temp);
	return (1);
}
