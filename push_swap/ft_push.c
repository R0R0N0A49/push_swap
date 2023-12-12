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

char	**ft_push(char **src1, char **src2, char c)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	len = ft_len_tab(src1) + 1;
	result = malloc ((len + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	result[j++] = ft_malloc_str(src2[0]);
	while (src1 && src1[i])
		result[j++] = ft_malloc_str(src1[i++]);
	while (j <= len)
	{
		result[j] = NULL;
		j++;
	}
	if (src1)
		ft_free(src1);
	ft_printf("p%c\n", c);
	return (result);
}
