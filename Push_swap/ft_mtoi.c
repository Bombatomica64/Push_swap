/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:57:56 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/12 12:45:09 by lmicheli         ###   ########.fr       */
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

int	fake_atoi(char *str, int nbr)
{
	int				i;
	int				flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if ((str[0] == '-' || str[0] == '+') && flag == 0)
		{
			if (str[i] == '-')
				flag = -1;
			else if (str[i] == '+')
				flag = 1;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (0);
			i++;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (flag * nbr > 2147483647 || flag * nbr < -2147483648)
		return (0);
	return (1);
}

int	ft_check_for_non_int(char *str)
{
	long long int	nbr;
	int				i;

	i = 1;
	nbr = 0;
	if (ft_strlen(str) > 11)
		return (0);
	i = fake_atoi(str, nbr);
	return (i);
}

int	*ft_mtoi(char **array, int args)
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
		if (ft_check_for_non_int(array[i]) == 0)
		{
			if (args == 2)
				ft_free_matrix(array);
			free(stack);
			ft_error();
		}
		stack[i] = ft_atoi(array[i]);
		i++;
	}
	check_for_dupes(stack, i);
	return (stack);
}
// Path: ft_mtoi.c
// Compare this snippet from Push_swap.h: