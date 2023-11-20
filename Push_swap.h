/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:58:05 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/20 17:25:41 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

int		ft_check_stack(char **array);
int		ft_min(int a, int b);
int		ft_check_for_non_int(char *str);
int		*ft_mtoi(char **array);
void	ft_sort(int *stack_a, int *stack_b, int size);
void	ft_free_matrix(char **array);

#endif