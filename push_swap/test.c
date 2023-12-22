/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:44:25 by trebours          #+#    #+#             */
/*   Updated: 2023/12/21 10:44:26 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_average(int	*tab_a, int len_chunk, int len)
{
	int				i;
	unsigned int	result;

	result = 0;
	i = 0;
	while (i < (len - 1) && i < len_chunk)
	{
		result += tab_a[i];
		i++;
	}
	result /= len_chunk;
	return (result);
}

int	*ft_sort_2(int *tab_b, int len)
{
	int	i;
	int	j;

	i = ft_verif_revers(tab_b, len) - 1;
	j = i;
	if (i == 0)
	{
		tab_b = ft_rotate(tab_b, 'b', len);
		return  (tab_b);
	}
	while (i > 0)
	{
		tab_b = ft_rotate(tab_b, 'b', len);
		i--;
	}
	tab_b = ft_swap(tab_b, 'b');
	while (j > 0)
	{
		tab_b = ft_reverse(tab_b, 'b',len);
		if (tab_b[1] > tab_b[0])
			tab_b = ft_swap(tab_b, 'b');
		j--;
	}
	return (tab_b);
}

int	*ft_sort_1(int *tab_b, int len)
{
	int	i;
	int	j;
	int save;

	i = (ft_verif_revers(tab_b, len))* -1;
	j = 0;
	save = tab_b[i];
	while (tab_b[0] != save)
	{
		tab_b = ft_reverse(tab_b, 'b', len);
		i--;
		j++;
	}
	tab_b = ft_reverse(tab_b, 'b', len);
	tab_b = ft_swap(tab_b, 'b');
	tab_b = ft_rotate(tab_b, 'b',len);
	while (j > 0)
	{
		tab_b = ft_rotate(tab_b, 'b',len);
		j--;
	}
	return (tab_b);
}
