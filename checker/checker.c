/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:31:58 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/16 15:16:36 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_checker.h"

void	ft_make_move(char *line, t_stack **a_stack, t_stack **b_stack)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_sa_no_print(a_stack);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_sb_no_print(b_stack);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_ss_no_print(a_stack, b_stack);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_pa_no_print(a_stack, b_stack);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_pb_no_print(a_stack, b_stack);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra_no_print(a_stack);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrb_no_print(b_stack);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrr_no_print(a_stack, b_stack);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_ra_no_print(a_stack);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb_no_print(b_stack);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr_no_print(a_stack, b_stack);
	else
		ft_error();
}

void	ft_check_moves(int *stack_a, int *stack_b, int size)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		sorted;
	char	*line;

	a_stack = ft_make_list(stack_a, size);
	b_stack = ft_make_list(stack_b, 0);
	free(stack_a);
	free(stack_b);
	sorted = check_if_sorted(&a_stack);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		ft_make_move(line, &a_stack, &b_stack);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	sorted = check_if_sorted(&a_stack);
	if (b_stack)
		sorted = 0;
	ft_free_all_stack(&a_stack, &b_stack);
	if (sorted != 0)
		ft_ok();
	else
		ft_ko();
}

int	main(int args, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	char	**stack_pre;

	if (args <= 1)
		return (-1);
	else if (args == 2)
		stack_pre = ft_split(argv[1], ' ');
	else
		stack_pre = &argv[1];
	stack_a = ft_mtoi(stack_pre, args);
	if (args == 2)
	{
		args = ft_matrix_len(stack_pre);
		ft_free_matrix(stack_pre);
	}
	else
		args = ft_matrix_len(stack_pre);
	stack_b = NULL;
	if (args == 2)
		ft_free_matrix(stack_pre);
	ft_check_moves(stack_a, stack_b, args);
}
