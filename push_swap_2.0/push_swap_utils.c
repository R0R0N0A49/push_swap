/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:07:00 by trebours          #+#    #+#             */
/*   Updated: 2023/12/12 11:07:05 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *src)
{
	int	i;
	int	mult;
	int	rsl;

	rsl = 0;
	mult = 1;
	i = 0;
	if (src[0] == '-')
		mult = -1;
	if (src[0] == '-' || src[0] == '+')
		i++;
	while (src[i])
	{
		rsl = rsl * 10 + (src[i] - '0');
		i++;
	}
	return (rsl * mult);
}

int	ft_len_tab(char **src)
{
	int	i;

	if (!src || (src && !src[0]))
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_free(char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src[i]);
	free(src);
}

char	**ft_malloc_push(char **src)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	len = ft_len_tab(src);
	if ((len - 1) == 0)
	{
		ft_free(src);
		return (NULL);
	}
	result = malloc (ft_len_tab(src) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 1;
	j = 0;
	while (src[i])
	{
		result[j] = ft_malloc_str(src[i]);
		i++;
		j++;
	}
	result[j] = 0;
	ft_free(src);
	return (result);
}

char	**ft_malloc_first_tab(char **src)
{
	int		i;
	char	**result;

	i = 0;
	result = malloc((ft_len_tab(src) + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (src[i])
	{
		result[i] = ft_malloc_str(src[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
