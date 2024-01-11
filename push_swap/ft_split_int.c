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

static int	ft_strdup_mod(char *s, char chr)
{
	char	tmp[1000];
	int		i;

	i = 0;
	while (s[i] && s[i] != chr)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (ft_atoi(tmp));
}

static int	loop(int **tab, char *s, char c)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			if (ft_atol(&s[i], c))
				return (1);
			tab[0][j++] = ft_strdup_mod(&s[i], c);
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (0);
}

int	*ft_split(char *s, char c, int *len)
{
	int	i;
	int	*tab;

	i = 0;
	*len = ft_count(s, c);
	if (!s)
		return (0);
	tab = malloc((*len) * sizeof(int));
	if (!tab)
		return (0);
	if (loop(&tab, s, c))
		return (0);
	free(s);
	return (tab);
}
