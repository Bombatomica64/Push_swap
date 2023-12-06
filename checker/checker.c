/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:31:58 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/06 15:02:00 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_checker.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_make_move(char *line, t_stack **a_stack, t_stack **b_stack)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		ft_sa_no_print(a_stack);
	else if (ft_strncmp(line, "sb", 2) == 0)
		ft_sb_no_print(b_stack);
	else if (ft_strncmp(line, "ss", 2) == 0)
		ft_ss_no_print(a_stack, b_stack);
	else if (ft_strncmp(line, "pa", 2) == 0)
		ft_pa_no_print(a_stack, b_stack);
	else if (ft_strncmp(line, "pb", 2) == 0)
		ft_pb_no_print(a_stack, b_stack);
	else if (ft_strncmp(line, "ra", 2) == 0)
		ft_ra_no_print(a_stack);
	else if (ft_strncmp(line, "rb", 2) == 0)
		ft_rb_no_print(b_stack);
	else if (ft_strncmp(line, "rr", 2) == 0)
		ft_rr_no_print(a_stack, b_stack);
	else if (ft_strncmp(line, "rra", 3) == 0)
		ft_rra_no_print(a_stack);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		ft_rrb_no_print(b_stack);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		ft_rrr_no_print(a_stack, b_stack);
	else
		ft_error();
}

void	ft_check_moves(int *stack_a, int *stack_b, int size)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		sorted;
	int		read_bytes;
	char	*line;

	a_stack = ft_make_list(stack_a, size);
	b_stack = ft_make_list(stack_b, 0);
	sorted = check_if_sorted(&a_stack);
	line = get_next_line(1);
	read_bytes = ft_strlen(line);
	while (read_bytes > 0)
	{
		ft_make_move(line, &a_stack, &b_stack);
		line = get_next_line(1);
		read_bytes = ft_strlen(line);
	}
	sorted = check_if_sorted(&a_stack);
	if (sorted && !b_stack)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int args, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	char	**stack_pre;

	if (args <= 1)
		return (0);
	else if (args == 2)
		stack_pre = ft_split(argv[1], ' ');
	else
		stack_pre = &argv[1];
	stack_a = ft_mtoi(stack_pre);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		ft_free_matrix(stack_pre);
		return (0);
	}
	args = ft_matrix_len(stack_pre);
	stack_b = NULL;
	ft_check_moves(stack_a, stack_b, args);
}
