/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 10:39:34 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:23:20 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_occurence(char *s, char c)
{
	int i;
	int find;

	i = 0;
	find = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			find++;
		i++;
	}
	return (find);
}

static void	*ft_free(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	if (i > 0)
	{
		while (tab[j])
		{
			free(tab[j]);
			j++;
		}
	}
	else
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char	**ft_split2(char *str, int i, char **tab, char c)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	while (str[i])
	{
		while (str[i + n] != c && str[i + n])
			n++;
		if (str[i + n] == c || str[i + n] == '\0')
			i = i + n;
		if (n > 0 && str[i - 1])
		{
			if ((tab[j++] = ft_substr(str, i - n, n)) == NULL)
				return (ft_free(tab));
		}
		n = 0;
		if (str[i] == '\0')
			i--;
		i++;
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	char	*str;
	char	**tab;

	str = (char*)s;
	if (!str)
		return (NULL);
	if (((tab = malloc((ft_occurence(str, c) + 1) * sizeof(char*))) == NULL))
		return (NULL);
	tab = ft_split2(str, 0, tab, c);
	return (tab);
}
