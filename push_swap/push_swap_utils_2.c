/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:30:44 by trebours          #+#    #+#             */
/*   Updated: 2023/12/12 14:30:48 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rsl;
	int		j;
	int		i;

	j = 0;
	i = 0;
	rsl = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (rsl == 0)
		return (0);
	while ((s1 && s1[i]))
	{
		rsl[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		rsl[i + j] = s2[j];
		j++;
	}
	rsl[i + j] = ' ';
	rsl[i + j + 1] = '\0';
	if (s1)
		free(s1);
	return (rsl);
}

void	error(char *src)
{
	write (2, "Error\n", 6);
	free(src);
}

int	ft_verif_test(int len_chunk, int *tab_a, int *tab_b, int len_a)
{
	int verif;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len_a && i < len_chunk)
	{
		j += tab_a[i];
		i++;
	}
	verif = j / len_chunk;
	if (tab_b[0] > verif)
		return (1);
	return (0);
}

int	*ft_sort_b(int *tab_b, int *tab_a, int len, int len_chunk, int len_a)
{
	int	i;
	int	mid_len;

	i = 1;
	mid_len = len / 2;
	if (i <= mid_len)
	{
		if (tab_b[0] < tab_b[1])
		{
			tab_b = ft_swap(tab_b, 'b', len);
		}
		if (len > 2 && ft_verif_test(len_chunk, tab_a, tab_b, len_a))
			tab_b = ft_reverse(tab_b, 'b', len);
	}
	i = len - 1;
	if(i > mid_len)
	{
		if (tab_b[len - 2] > tab_b[len - 1])
		{
			tab_b = ft_rotate(tab_b, 'b', len);
			tab_b = ft_swap(tab_b, 'b', len);
			tab_b = ft_reverse(tab_b, 'b', len);
		}
	}
	return (tab_b);
}
