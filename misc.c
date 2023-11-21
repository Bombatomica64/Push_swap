/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:16:11 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/21 17:16:37 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	make_lists(int *stack_a, int *stack_b, int size)
{
	int				i;
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;

	a_stack = ft_make_list(stack_a, size);
	b_stack = ft_make_list(stack_b, size);
}
