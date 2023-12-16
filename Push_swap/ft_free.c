/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:17:49 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/16 13:22:53 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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
	array = NULL;
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

void	ft_free_all_stack(t_stack **a_stack, t_stack **b_stack)
{
	ft_free_stack(a_stack);
	ft_free_stack(b_stack);
}

void	ft_free_all_stack_exit(t_stack **a_stack, t_stack **b_stack)
{
	ft_free_all_stack(a_stack, b_stack);
	exit(0);
}
