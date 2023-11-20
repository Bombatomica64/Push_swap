/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:57:56 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/20 17:25:11 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_check_for_non_int(char *str)
{
	long long int	nbr;
	int				i;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == '-' && i == 0)
		{
			i++;
			continue ;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
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
		if (!ft_check_for_non_int(array[i]))
			stack[i] = ft_atoi(array[i]);
		else
		{
			write(2, "Error\n", 6);
			ft_free_matrix(array);
			exit(0);
		}
		i++;
	}
	return (stack);
}
// Path: ft_mtoi.c
// Compare this snippet from Push_swap.h: