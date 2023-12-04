/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:31:58 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/04 17:38:13 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_checker.h"

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
	}
	else if (args > 2)
		stack_pre = argv + 1;
	stack_a = ft_mtoi(stack_pre);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	args = ft_matrix_len(stack_pre);
	stack_b = NULL;
}
