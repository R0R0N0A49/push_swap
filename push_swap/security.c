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

int	ft_order(int *tab_a, int len_a)
{
	int	i;

	i = 0;
	while (i + 1 < len_a)
	{
		if (tab_a[i] > tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_verif_repeat(int *tab_a, int len_a)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (len_a > 1 && i < len_a - 1)
	{
		if (tab_a[i] == tab_a[j])
			return (1);
		else if (j < len_a - 1)
			j++;
		else
		{
			i++;
			j = i + 1;
		}
	}
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
		if ((src[i] >= '0' && src[i] <= '9') && src[i + 1] != '+'
			&& src[i + 1] != '-')
			i++;
		else if (src[i] == '-' && (src[i + 1] >= '0' || src[i + 1] <= '9'))
			i++;
		else if (src[i] == '+' && (src[i + 1] >= '0' && src[i + 1] <= '9'))
			i++;
		else if (src[i] == ' ' && src[i + 1] != ' ' && src[i + 1] != '\0')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_atol(char *s, char c)
{
	long	num;
	int		i;
	int		mult;

	mult = 1;
	num = 0;
	i = 0;
	if (s[0] == '-')
		mult = -1;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i] && s[i] != c)
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	num *= mult;
	if (num > -2147483649 && 2147483648 > num)
		return (0);
	return (1);
}
