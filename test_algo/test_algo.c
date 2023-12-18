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

void	ft_push_swap(char **tab_a)
{
	char	**tab_b;
	int		len_b;

	tab_b = NULL;
	while (ft_verif_order(tab_a, tab_b, 1))
	{
		while (ft_verif_order(tab_a, tab_b, 0))
		{
			if (ft_verif_first_a(tab_a) == 1)
				tab_a = ft_rotate_a(tab_a);
			else if (ft_verif_first_a(tab_a) == -1)
				tab_a = ft_reverse_a(tab_a);
			else if (ft_atoi(tab_a[0]) > ft_atoi(tab_a[1]))
				tab_a = ft_swap(tab_a, 'a');
			else
			{
				tab_b = ft_push(tab_b, tab_a, 'b');
				tab_a = ft_malloc_push(tab_a);
				break ;
			}
		}
		if (tab_b && ft_verif_revers_order(tab_b))
		{
			len_b = ft_len_tab(tab_b);
			if (len_b > 1 && ft_verif_first_a(tab_b) == -1)
				tab_b = ft_rotate_b(tab_b);
			else if (len_b > 1 && ft_verif_first_a(tab_b) == 1)
				tab_b = ft_reverse_b(tab_b);
			else if (len_b > 1 && ft_atoi(tab_b[0]) > ft_atoi(tab_b[1]))
				tab_b = ft_swap(tab_b, 'b');
		}
		if (tab_b && ft_verif_order(tab_a, tab_b, 0) == 0)
		{
			tab_a = ft_push(tab_a, tab_b, 'a');
			tab_b = ft_malloc_push(tab_b);
		}
	}
	if (tab_b)
		ft_free(tab_b);
	ft_free(tab_a);
}
