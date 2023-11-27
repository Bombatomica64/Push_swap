/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:03:04 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/27 12:18:58 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_sort(int *stack_a, int *stack_b, int size)
{
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;

	a_stack = ft_make_list(stack_a, size);
	b_stack = ft_make_list(stack_b, size);
	if (size <= 3)
	{
		ft_sort_three(&a_stack);
		return ;
	}
	else if (size <= 5)
	{
		ft_sort_5(&a_stack);
		return ;
	}
	return ;
}

int	main(int args, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	char	**stack_pre;

	if (args <= 1)
		return (0);
	if (args == 2)
	{
		stack_pre = ft_split(argv[1], ' ');
		ft_check_stack(stack_pre);
	}
	else
	{
		stack_pre = argv + 1;
	//	ft_check_stack(stack_pre);
	}
	stack_a = ft_mtoi(argv + 1);
	if (!stack_a)
	{
		write(2, "Error:1\n", 7);
		return (0);
	}
	args = ft_matrix_len(stack_pre);
	//ft_free_matrix(stack_pre);
	stack_b = NULL;
	ft_sort(stack_a, stack_b, args);
	ft_printf("OK\n");
	return (0);
}
