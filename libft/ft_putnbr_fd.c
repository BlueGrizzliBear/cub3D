/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:37:08 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:23:08 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n <= 0)
	{
		if (n == 0)
			ft_putchar_fd('0', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n / -10, fd);
			ft_putchar_fd(n % 10 * -1 + '0', fd);
		}
		else if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n * -1, fd);
		}
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	if (n <= 9 && n > 0)
		ft_putchar_fd(n + '0', fd);
}
