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

int	ft_len_tab(int *src)
{
	int	i;

	if (!src || (src && !src[0]))
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	*ft_malloc_push(int *src, int len)
{
	int	*result;
	int	i;
	int	j;

	if ((len - 1) == 0)
	{
		free(src);
		return (NULL);
	}
	result = malloc (len * sizeof(int));
	if (!result)
		return (NULL);
	i = 1;
	j = 0;
	while (i < len)
	{
		result[j] = src[i];
		i++;
		j++;
	}
	free(src);
	return (result);
}
