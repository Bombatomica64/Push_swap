/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:56:35 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/22 18:19:55 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	else
		return (NULL);
	return (new_node);
}
/*

int main(void) {
	// Create a new node with content "Hello, world!"
	t_list *node = ft_lstnew("Hello, world!");

	// Check if the node was created successfully
	if (node != NULL) {
		printf("New node created successfully.\n");
		printf("Content: %s\n", (char *)node->content);
	} else {
		printf("Failed to create new node.\n");
	}

	return 0;
}
 */