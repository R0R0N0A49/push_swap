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

int	*ft_rotate_a(int *src, char c)
{
	int	*result;
	int	len;
	int	i;
	int	j;

	len = ft_len_tab(src);
	result = malloc ((len + 1) * sizeof(int));
	if (!result)
		return (0);
	i = 1;
	j = 0;
	while (i < len)
	{
		result[j] = src[i];
		i++;
		j++;
	}
	result[j] = src[0];
	result[len] = 0;
	free(src);
	ft_printf("r%c\n", c);
	return (result);
}

int	*ft_rotate_b(int *src)
{
	int	*result;
	int	len;
	int	i;
	int	j;

	len = ft_len_tab(src);
	result = malloc (len * sizeof(int));
	if (!result)
		return (0);
	i = 1;
	j = 0;
	while (i < len)
	{
		result[j] = src[i];
		i++;
		j++;
	}
	result[j] = src[0];
	free(src);
	ft_printf("rb\n");
	return (result);
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
/* 
int	*ft_reverse_b(int *src)
{
	int	*result;
	int	len;
	int	i;
	int	j;

	len = ft_len_tab(src);
	result = malloc ((len) * sizeof(int));
	if (!result)
		return (0);
	i = 1;
	j = 0;
	while (i < len)
	{
		result[i] = src[j];
		i++;
		j++;
	}
	result[0] = src[j];
	result[len] = 0;
	free(src);
	ft_printf("rrb\n");
	return (result);
}
 */