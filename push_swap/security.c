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

void	ft_order(int **tab_a, int **tab_b, int len_a, int len_b)
{
	while (len_b > 0)
	{
			if (len_b >= 2 && tab_b[0][len_b - 1] > tab_b[0][0])
			{
				*tab_b = ft_reverse(*tab_b, 'b', len_b);
				*tab_a = ft_push(*tab_a, *tab_b, len_a++, 'a');
				*tab_b = ft_malloc_push(*tab_b, len_b--);
			}
			else
			{
				*tab_a = ft_push(*tab_a, *tab_b, len_a++, 'a');
				*tab_b = ft_malloc_push(*tab_b, len_b--);
			}
	}
}

int	ft_verif_revers(int *src, int len)
{
//doit verifier si b en possition buterfly
//en verifiant les moitier
	int	i;

	i = 1;
	while (len > 2 && i <= len / 2)
	{
		if (src[i] > src[i - 1])
			return (i);
		i++;
	}
	while(len > 2 && i < len)
	{
		if (src[i] < src[i - 1])
			return (i * -1);
		i++;
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
		if ((src[i] >= '0' && src[i] <= '9')
			|| src[i] == '-' || src[i] == '+' || src[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_verif_first(int *src, int len)
{
	if (len == 1)
		return (0);
	if (src[0] >= src[len])
	{
		if (src[0] > src[len]
			&& (len > 3 && src[len] < src[len - 1]))
			return (-1);
		else if (src[0] > src[len])
			return (1);
		else if (src[0] == src[len])
		{
			if (src[len] > src[len - 1])
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}
