/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:08:53 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/13 17:09:14 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static	int	ft_countwords(const	char	*str, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		n++;
		while (str[i] != c && str[i])
			i++;
		while (str[i] == c && str[i])
			i++;
	}
	return (n);
}

static char	*ft_get_words(const	char *str, char c)
{
	char	*ret;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while ((str[len] != c) && str[len])
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		n;

	n = ft_countwords(s, c);
	i = 0;
	tab = malloc(sizeof(const char *) * (n + 1));
	if (!tab)
		return (free_tab(tab));
	tab[n] = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		tab[i] = ft_get_words(s, c);
		if (!tab[i])
			return (free_tab(tab));
		i++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (tab);
}
