/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:43:29 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/15 16:11:47 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	ft_check_stack(char **array)
{
	int		i;
	char	*temp;
	int		j;
	int		min;

	i = 0;
	while (array[i])
	{
		temp = array[i];
		j = i;
		while (array[j])
		{
			min = ft_max(ft_strlen(temp), ft_strlen(array[j]));
			if (ft_strncmp(temp, array[j++], min) == 0)
			{
				write (2, "Error:0\n", 7);
			//	ft_free_matrix(array);
				exit(0);
			}
		}
		i++;
	}
	free(temp);
	return (1);
}
