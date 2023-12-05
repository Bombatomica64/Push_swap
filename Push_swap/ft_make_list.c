/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:48:46 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/04 18:32:54 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

t_stack	*ft_make_list(int *stack, int size)
{
	t_stack			*stack_a;
	t_stack			*new_node;
	t_stack			*prev_node;
	int				i;

	i = 0;
	stack_a = NULL;
	if (stack == NULL)
		return (stack_a);
	while (i < size)
	{
		new_node = ft_stack_node_new(stack[i]);
		ft_node_add_back(&stack_a, new_node);
		if (i > 0)
			new_node->prev = prev_node;
		prev_node = new_node;
		i++;
	}
	return (stack_a);
}

t_stack	*ft_stack_node_new(int nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node)
	{
		new_node->nbr = nbr;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
		return (NULL);
	return (new_node);
}

void	ft_node_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

t_stack	*ft_lst_first(t_stack **stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = *stack;
	while (current->prev != NULL)
		current = current->prev;
	return (current);
}

t_stack	*ft_lst_last(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
