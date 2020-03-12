/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:44:54 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:20:46 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long n, int base, char index)
{
	int		size;

	size = 0;
	if (n < 0 && index != 'x' && index != 'X')
	{
		size++;
		n = -n;
	}
	while (n >= base)
	{
		size++;
		n = n / base;
	}
	return (size + 1);
}

char		*ft_ltoa_base(long n, int b, char i)
{
	int		size;
	char	*s;
	long	temp;

	temp = n;
	n = (temp < 0) ? -n : n;
	size = ft_size(temp, b, i);
	if (!(s = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s[size--] = '\0';
	while (n >= b)
	{
		if (n % b >= 10)
			s[size--] = (i == 'x' ? (n % b - 10) + 'a' : (n % b - 10) + 'A');
		else
			s[size--] = n % b + '0';
		n = n / b;
	}
	if (n >= 10)
		s[size--] = (i == 'x' ? (n - 10) + 'a' : (n - 10) + 'A');
	else
		s[size--] = n + '0';
	if (temp < 0)
		s[size] = '-';
	return (s);
}
