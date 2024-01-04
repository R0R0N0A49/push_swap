/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:40:10 by trebours          #+#    #+#             */
/*   Updated: 2023/12/15 10:40:16 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_push_swap(int *tab_a, int len_a)
{
	int	*tab_b;
	int	len_b = 0;

	tab_b = NULL;
	while (ft_verif_order(tab_a, len_a, len_b, 1))
	{
		while (ft_verif_order(tab_a, len_a, len_b, 0))
		{
			if (len_a > 0 && ft_verif_first(tab_a, len_a - 1) == 1)
				tab_a = ft_rotate_a(tab_a, 'a');
			else if (len_a > 0 && ft_verif_first(tab_a, len_a - 1) == -1)
				tab_a = ft_reverse(tab_a, 'a', len_a - 1);
			else if (len_a > 0 && tab_a[0] > tab_a[1])
				tab_a = ft_swap(tab_a, 'a', len_a);
			else if (len_a > 0)
			{
				tab_b = ft_push(tab_b, tab_a, 'b', len_b);
				tab_a = ft_malloc_push(tab_a, len_a);
				len_a--;
				len_b++;
				break ;
			}
		}
		if (tab_b && ft_verif_revers_order(tab_b, len_b))
		{
			if (len_b > 1 && ft_verif_first(tab_b, len_b - 1) == -1)
				tab_b = ft_rotate_b(tab_b);
			else if (len_b > 1 && ft_verif_first(tab_b, len_b - 1) == 1)
				tab_b = ft_reverse(tab_b, 'b', len_b - 1);
			else if (len_b > 1 && tab_b[0] > tab_b[1])
				tab_b = ft_swap(tab_b, 'b', len_b);
		}
		if (tab_b && ft_verif_order(tab_a, len_a, len_b, 0) == 0)
		{
			tab_a = ft_push(tab_a, tab_b, 'a', len_a);
			tab_b = ft_malloc_push(tab_b, len_b);
			len_a++;
			len_b--;
		}
	}
	ft_display(tab_a, tab_b, len_a, len_b);
	if (tab_b)
		free(tab_b);
	free(tab_a);
}

fonctione bien :

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
			else if ((len_a > 1 && len_b > 1) && (tab_a[0]) > (tab_a[1]) && len_b > 1 && (tab_b[0]) < (tab_b[1]))
				ft_ss(&tab_a, &tab_b);
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
				else if ((len_a > 1 && len_b > 1) && (tab_a[0]) > (tab_a[1]) && len_b > 1 && (tab_b[0]) < (tab_b[1]))
					ft_ss(&tab_a, &tab_b);
				else if (len_b > 1 && (tab_b[0]) < (tab_b[1]))
					tab_b = ft_swap(tab_b, 'b');
				else
					break ;
			}
		}
		if (len_b > 0 && ft_order(tab_a, len_a, len_b, 1) == 0)
		{
			if (tab_b[0] < tab_b[len_b - 1])
				ft_reverse(tab_b, 'b', len_b);
			tab_a = ft_push(tab_a, tab_b, len_a++, 'a');
			tab_b = ft_malloc_push(tab_b, len_b--);
		}
	}
	if (tab_b)
		free(tab_b);
	free(tab_a);
}
