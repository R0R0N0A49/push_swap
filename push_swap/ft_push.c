/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:18 by trebours          #+#    #+#             */
/*   Updated: 2023/12/08 14:47:21 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_push(int *src1, int *src2, int len, char c)
{
	int	*result;
	int	i;
	int	j;

	result = malloc ((len + 1) * sizeof(int));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	result[j++] = src2[0];
	while (i < len)
		result[j++] = src1[i++];
	free(src1);
		ft_printf("p%c\n", c);
	return (result);
}
