/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:53:13 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/11 16:51:48 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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
