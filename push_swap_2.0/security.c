/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:55:19 by trebours          #+#    #+#             */
/*   Updated: 2023/12/08 14:55:24 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_order(char **src, char **verif, int secu)
{
	int	i;
	int	j;

	if (!src)
		return (0);
	j = 1;
	i = 0;
	while (src[j])
	{
		if (ft_atoi(src[i]) > ft_atoi(src[j]))
			return (1);
		i++;
		j++;
	}
	if (secu == 1 && verif)
		return (1);
	else
		return (0);
}

int	ft_verif_revers_order(char **src)
{
	int	i;
	int	j;

	if (!src)
		return (0);
	j = 1;
	i = 0;
	while (src[j])
	{
		if (ft_atoi(src[i]) < ft_atoi(src[j]))
			return (1);
		i++;
		j++;
	}
	if (ft_len_tab(src) == 1)
		return (1);
	return (0);
}

int	ft_verif_int(char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		if ((src[i] >= '0' && src[i] <= '9')
			|| src[i] == '-' || src[i] == '+' || src[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_verif_first_a(char **src)
{
	int	len;

	len = ft_len_tab(src) - 1;
	if (len == 1)
		return (0);
	if (ft_atoi(src[0]) >= ft_atoi(src[len]))
	{
		if (ft_atoi(src[0]) > ft_atoi(src[len])
			&& (len > 3 && ft_atoi(src[len]) < ft_atoi(src[len - 1])))
			return (-1);
		else if (ft_atoi(src[0]) > ft_atoi(src[len]))
			return (1);
		else if (ft_atoi(src[0]) == ft_atoi(src[len]))
		{
			if (ft_atoi(src[len]) > ft_atoi(src[len - 1]))
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}
