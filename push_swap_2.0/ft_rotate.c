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

char	*ft_malloc_str(char *src)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(src);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_rotate_a(char **src)
{
	char	**result;
	int		len;
	int		i;
	int		j;

	len = ft_len_tab(src);
	result = malloc ((len + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 1;
	j = 0;
	while (i < len)
	{
		result[j] = ft_malloc_str(src[i]);
		i++;
		j++;
	}
	result[j] = ft_malloc_str(src[0]);
	result[len] = 0;
	ft_free(src);
	ft_printf("ra\n");
	return (result);
}

char	**ft_rotate_b(char **src)
{
	char	**result;
	int		len;
	int		i;
	int		j;

	len = ft_len_tab(src);
	result = malloc ((len + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 1;
	j = 0;
	while (i < len)
	{
		result[j] = ft_malloc_str(src[i]);
		i++;
		j++;
	}
	result[j] = ft_malloc_str(src[0]);
	result[len] = 0;
	ft_free(src);
	ft_printf("rb\n");
	return (result);
}

char	**ft_reverse_a(char **src)
{
	char	**result;
	int		len;
	int		i;
	int		j;

	len = ft_len_tab(src);
	result = malloc ((len + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 1;
	j = 0;
	while (i < len)
	{
		result[i] = ft_malloc_str(src[j]);
		i++;
		j++;
	}
	result[0] = ft_malloc_str(src[j]);
	result[len] = 0;
	ft_free(src);
	ft_printf("rra\n");
	return (result);
}

char	**ft_reverse_b(char **src)
{
	char	**result;
	int		len;
	int		i;
	int		j;

	len = ft_len_tab(src);
	result = malloc ((len + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 1;
	j = 0;
	while (i < len)
	{
		result[i] = ft_malloc_str(src[j]);
		i++;
		j++;
	}
	result[0] = ft_malloc_str(src[j]);
	result[len] = 0;
	ft_free(src);
	ft_printf("rrb\n");
	return (result);
}
