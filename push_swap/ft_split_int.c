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

int	*ft_split(char *s, char c, int *len)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	*len = ft_count(s, c);
	if (!s)
		return (0);
	tab = malloc((*len) * sizeof(int));
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
	free(s);
	return (tab);
}
