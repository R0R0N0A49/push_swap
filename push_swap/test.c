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

void	ft_end(int **tab_a, int **tab_b, int len_a, int len_b)
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

	i = ft_verif_revers(tab_b, len)/*  - 1 */;
	j = len / 2;
	if (i == 0)
	{
		tab_b = ft_rotate(tab_b, 'b', len);
		return (tab_b);
	}
	while (i > 0)
	{
		tab_b = ft_rotate(tab_b, 'b', len);
		i--;
	}
	tab_b = ft_swap(tab_b, 'b');
	while (j > 0)
	{
		tab_b = ft_reverse(tab_b, 'b', len);
		if (tab_b[1] > tab_b[0])
			tab_b = ft_swap(tab_b, 'b');
		/* else if (tab_b[1] < tab_b[0])
			return (tab_b); */
		j--;
	}
	return (tab_b);
}

int	*ft_sort_1(int *tab_b, int len)
{
	int	i;
	int	j;
	int	save;

	i = (ft_verif_revers(tab_b, len)) * -1;
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
	tab_b = ft_rotate(tab_b, 'b', len);
	while (j > 0)
	{
		if (tab_b[1] < tab_b[0])
			tab_b = ft_swap(tab_b, 'b');
		tab_b = ft_rotate(tab_b, 'b', len);
		/* if (tab_b[len - 1] < tab_b[len - 2])
			return (tab_b ); */
		j--;
	}
	return (tab_b);
}

void	algo_for_ten(int *tab_a, int len_a)
{
	int	*tab_b;
	int	len_b;

	tab_b = NULL;
	len_b = 0;
	while (ft_order(tab_a, len_a, len_b, 0))
	{
		while (ft_order(tab_a, len_a, len_b, 1))
		{
			if (len_a > 1 && ft_verif_first(tab_a, len_a - 1) == 1)
				tab_a = ft_rotate(tab_a, 'a', len_a);
			else if (len_a > 1 && ft_verif_first(tab_a, len_a - 1) == -1)
				tab_a = ft_reverse(tab_a, 'a', len_a);
			else if (len_a > 1 && (tab_a[0]) > (tab_a[1]))
				tab_a = ft_swap(tab_a, 'a');
			else
			{
				tab_b = ft_push(tab_b, tab_a, len_b++ ,'b');
				tab_a = ft_malloc_push(tab_a, len_a--);
			}
			while (tab_b && ft_order_reverse(tab_b, len_b))
			{
				if (len_b > 1 && ft_verif_first(tab_b, len_b - 1) == 1)
					tab_b = ft_rotate(tab_b, 'b', len_b);
				else if (len_b > 1 && ft_verif_first(tab_b, len_b - 1) == -1)
					tab_b = ft_reverse(tab_b, 'b', len_b);
				else if (len_b > 1 && (tab_b[0]) < (tab_b[1]))
					tab_b = ft_swap(tab_b, 'b');
				else
					break ;
			}
		}
		if (len_b > 0 && ft_order(tab_a, len_a, len_b, 1) == 0)
		{
			tab_a = ft_push(tab_a, tab_b, len_a++, 'a');
			tab_b = ft_malloc_push(tab_b, len_b--);
		}
	}
	if (tab_b)
		free(tab_b);
	free(tab_a);
}