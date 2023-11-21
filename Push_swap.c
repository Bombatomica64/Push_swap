/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:03:04 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/20 18:38:15 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_sort(int *stack_a, int *stack_b, int size)
{
	int				i;
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;

	a_stack = ft_make_list(stack_a, size);
	b_stack = ft_make_list(stack_b, size);
}

int	main(int args, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	char	**stack_pre;

	if (args <= 1)
	{
		return (0);
	}
	if (args == 2)
	{
		stack_pre = ft_split(argv[1], ' ');
		ft_check_stack(stack_pre);
	}
	else
	{
		stack_pre = argv + 1;
		ft_check_stack(stack_pre);
	}
	stack_a = ft_mtoi(stack_pre);
	args = ft_matrix_len(stack_pre);
	ft_free_matrix(stack_pre);
	stack_b = NULL;
	ft_sort(stack_a, stack_b, args);
	return (0);
}
