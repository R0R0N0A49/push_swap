/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:48 by trebours          #+#    #+#             */
/*   Updated: 2023/12/08 14:47:50 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_swap(int *src, char c)
{
	int	tmp;

	tmp = src[0];
	src[0] = src[1];
	src[1] = tmp;
	/* int	*result;
	int	i;

	result = malloc (len * sizeof(int));
	if (!result)
		return (0);
	result[0] = src[1];
	result[1] = src[0];
	i = 2;
	while (i < len)
	{
		result[i] = src[i];
		i++;
	}
	free(src); */
	ft_printf("s%c\n", c);
	return (src);
}
