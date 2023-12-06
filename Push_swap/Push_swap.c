/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:03:04 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/06 13:11:34 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("number:%d\n", tmp->nbr);
		tmp = tmp->next;
	}
}

void	ft_sort(int *stack_a, int *stack_b, int size, int fd)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = ft_make_list(stack_a, size);
	b_stack = ft_make_list(stack_b, 0);
	if (check_if_sorted(&a_stack))
		return ;
	if (size <= 3)
	{
		ft_sort_three(&a_stack, fd);
		return ;
	}
	else if (size <= 5)
	{
		ft_sort_5(&a_stack, &b_stack, fd);
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
	stack_pre = NULL;
	if (args == 2)
	{
		stack_pre = ft_split(argv[1], ' ');
	}
	else if (args > 2)
		stack_pre = argv + 1;
	stack_a = ft_mtoi(stack_pre);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		ft_free_matrix(stack_pre);
		return (0);
	}
	args = ft_matrix_len(stack_pre);
	stack_b = NULL;
	ft_sort(stack_a, stack_b, args, 1);
	return (0);
}
