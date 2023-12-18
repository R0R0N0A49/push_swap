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

char	**ft_swap(char **src, char c)
{
	char	**result;
	int		len;
	int		i;

	len = ft_len_tab(src);
	result = malloc ((len + 1) * sizeof(char *));
	if (!result)
		return (0);
	result[0] = ft_malloc_str(src[1]);
	result[1] = ft_malloc_str(src[0]);
	i = 2;
	while (i < len)
	{
		result[i] = ft_malloc_str(src[i]);
		i++;
	}
	result[len] = 0;
	ft_free(src);
	ft_printf("s%c\n", c);
	return (result);
}
