/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:03:04 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/30 12:26:28 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
}

void	ft_sort(int *stack_a, int *stack_b, int size, int fd)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = ft_make_list(stack_a, size);
	b_stack = ft_make_list(stack_b, 0);
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
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	fd = 1;
	if (args <= 1)
		return (0);
	if (args == 2)
	{
		stack_pre = ft_split(argv[1], ' ');
	//	ft_check_stack(stack_pre);
	}
	else if (args > 2)
		stack_pre = argv + 1;
	stack_a = ft_mtoi(stack_pre);
	if (!stack_a)
	{
		write(2, "Error1\n", 6);
		return (0);
	}
	args = ft_matrix_len(stack_pre);
	stack_b = NULL;
	ft_sort(stack_a, stack_b, args, fd);
//	ft_printf("OK\n");
	return (0);
}
