/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:03:04 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/20 16:57:43 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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
	ft_mtoi(stack_pre);
	return (0);
}
