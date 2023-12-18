/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:24:09 by trebours          #+#    #+#             */
/*   Updated: 2023/12/12 14:24:14 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(char *src, char c)
{
	int		j;
	int		i;
	int		len;

	if (!src)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(src) - 1;
	if (src[i] == c)
		i++;
	if (src[len] != c)
		j = 1;
	while (src[i])
	{
		if (src[i] == c && src[i - 1] != c)
			j++;
		i++;
	}
	return (j);
}

static unsigned int	ft_lenword(char *s, char chr)
{
	unsigned int	i;

	i = 0;
	while (s[i] != chr && s[i])
		i++;
	return (i);
}

static char	*ft_strdup_mod(char *s, char chr)
{
	char			*rsl;
	unsigned int	len_s;
	int				i;

	i = 0;
	len_s = ft_lenword(s, chr);
	rsl = (char *)malloc((len_s + 1) * sizeof(char));
	if (rsl == 0)
		return (0);
	while (s[i] && s[i] != chr)
	{
		rsl[i] = s[i];
		i++;
	}
	rsl[i] = 0;
	return (rsl);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	tab = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[j++] = ft_strdup_mod(&s[i], c);
			while (s[i] && s[i] != c)
				i++;
		}
	}
	tab[j] = 0;
	free(s);
	return (tab);
}
