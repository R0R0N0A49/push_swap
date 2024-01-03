/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:21:35 by trebours          #+#    #+#             */
/*   Updated: 2023/12/08 13:21:41 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk(int len)
{
	if (len > 249)
		return (len / 4);
	if (len > 99)
		return (len / 2);
	else if (len > 10)
		return (len);
	return (len);
}

void	ft_push_swap(int *tab_a, int len_a)
{
	int	*tab_b;
	int	len_b;
	int	len_chunk;
	int	chunk;
	int	i;


	if (ft_order(tab_a, len_a, 0, 0) == 0)
	{
		free (tab_a);
		return ;
	}
	len_b = 0;
	chunk = 0;
	tab_b = NULL;
	len_chunk = ft_chunk(len_a);
	i = 0;
	while (len_a > 0 && ft_order(tab_a, len_a, len_b, 1))
	{
		while (i < len_chunk && 0 < len_a)
		{
			tab_b = ft_push(tab_b, tab_a, len_b++, 'b');
			tab_a = ft_malloc_push(tab_a, len_a--);
			if (len_b > 2 && tab_b[0] % 2)
				tab_b = ft_rotate(tab_b, 'b', len_b);
			i++;
		}
		while (ft_verif_revers(tab_b, len_b) >= 1)
			tab_b = ft_sort_2(tab_b, len_b);
		while (ft_verif_revers(tab_b, len_b) <= -1)
			tab_b = ft_sort_1(tab_b, len_b);
		i = 0;
		chunk++;
	}
	ft_end(&tab_a, &tab_b, len_a, len_b);
	if (tab_b != NULL)
		free(tab_b);
	free(tab_a);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	int		*tab_a;

	i = 1;
	str = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			str = ft_strjoin(str, argv[i]);
			i++;
		}
		if (!ft_verif_int(str))
		{
			error(str);
			return (0);
		}
		tab_a = ft_split(str, ' ', &i);
		if (i > 1)
			ft_push_swap(tab_a, i);
		else
			algo_for_ten(tab_a, i);
	}
	return (0);
}
