/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:29:29 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:24:46 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_trimstart(char *s1, char *s2)
{
	int i;
	int j;
	int count;
	int start;

	i = 0;
	j = 0;
	count = 0;
	start = 0;
	while (s1[i])
	{
		if (count == 0)
		{
			while (s1[i] != s2[j] && s2[j])
				j++;
			if (!s2[j] || !s1[i + 1])
			{
				count = 1;
				start = i;
			}
		}
		j = 0;
		i++;
	}
	return (start);
}

static int		ft_trimend(char *s1, char *s2)
{
	int	i;
	int	j;
	int	count;
	int	end;

	i = 0;
	j = 0;
	count = 0;
	end = 0;
	while (i < (int)ft_strlen(s1))
	{
		if (count == 0)
		{
			while (s1[ft_strlen(s1) - i - 1] != s2[j] && s2[j] != '\0')
				j++;
			if (!s2[j] || !s1[i + 1])
			{
				count = 1;
				end = i;
			}
		}
		j = 0;
		i++;
	}
	return (end);
}

char			*ft_strtrim(const char *s1, const char *s2)
{
	size_t	start;
	size_t	end;
	char	*c;

	start = 0;
	end = 0;
	c = NULL;
	if (!(char*)s1)
		return (ft_calloc(sizeof(char), 1));
	if (!(char*)s2)
		return (ft_strdup(s1));
	start = ft_trimstart((char*)s1, (char*)s2);
	end = ft_trimend((char*)s1, (char*)s2);
	if (start + 1 == ft_strlen((char*)s1))
		return (ft_strdup(""));
	else
		c = ft_substr(s1, start, ft_strlen((char*)s1) - end - start);
	return (c);
}
