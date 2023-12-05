/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:10:27 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/29 17:39:50 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	stamp(char nb, int fd)
{
	write (fd, &nb, 1);
}

static void	ft_putnbr(int nb, int fd)
{
	long	a;
	long	b;

	a = nb;
	if (a < 0)
	{
		a = a * -1;
		write(fd, "-", 1);
	}
	if (a >= 10)
	{
		b = a / 10;
		ft_putnbr(b, fd);
		ft_putnbr(a % 10, fd);
	}
	else
	{
		stamp(a + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
/* #include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int main(void) {
	int num = 42;
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); // Open file for writing

	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}

	printf("Printing number %d to file descriptor %d:\n", num, fd);
	ft_putnbr_fd(num, fd);
	printf("\n");

	close(fd); // Close the file

	return 0;
}

 */