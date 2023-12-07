/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:53:13 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/07 17:19:09 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_checker.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_ko(void)
{
	write(1, "KO\n", 3);
	exit(0);
}

void	ft_ok(void)
{
	write(1, "OK\n", 3);
	exit(0);
}

char	*check_sorting_status(int sorted, t_stack *b_stack, int *read_bytes)
{
	char	*line;

	line = get_next_line(1);
	read_bytes = ft_strlen(line);
	if (sorted && !b_stack && !read_bytes)
		ft_ok();
	else if (!sorted && !b_stack && !read_bytes)
		ft_ko();
	else if (read_bytes == -1)
		ft_error();
	else if (read_bytes == 0)
	{
		free(line);
		return (NULL);
	}
	{
		
	}
	else
	{
		
	}	
	return (line);
}
