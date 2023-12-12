/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:57:56 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/12 10:46:07 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	check_for_dupes(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
			{
				free(stack);
				ft_error();
			}
			j++;
		}
		i++;
	}
}

int	ft_check_for_non_int(char *str)
{
	long long int	nbr;
	int				i;
	int				flag;

	i = 0;
	nbr = 0;
	flag = 0;
	if (ft_strlen(str) > 11)
		return (0);
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && flag == 0)
		{
			i++;
			flag = 1;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (flag == 1)
		nbr = -nbr;
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

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
		if (ft_check_for_non_int(array[i]) == 1)
			stack[i] = ft_atoi(array[i]);
		else
			ft_error();
		i++;
	}
	check_for_dupes(stack, i);
	return (stack);
}
// Path: ft_mtoi.c
// Compare this snippet from Push_swap.h: