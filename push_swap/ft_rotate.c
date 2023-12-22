/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:00 by trebours          #+#    #+#             */
/*   Updated: 2023/12/08 14:47:05 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_rotate(int *src, char c, int len)
{
	int	tmp;
	int	i;

	tmp = src[0];
	i = 1;
	while (i < len)
	{
		src[i - 1] = src[i];
		i++;
	}
	src[len - 1] = tmp;
	ft_printf("r%c\n", c);
	return (src);
}

int	*ft_reverse(int *src, char c, int len)
{
	int	tmp;
	int	i;

	tmp = src[0];
	src[0] = src[len - 1];
	i = len - 1;
	while (i > 1)
	{
		src[i] = src[i - 1];
		i--;
	}
	src[i] = tmp;
	ft_printf("rr%c\n", c);
	return (src);
}
