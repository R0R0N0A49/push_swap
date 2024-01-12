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

void	ft_sort(int **tab_a, int **tab_b, int len_a, int len_b)
{
	int	pos_max;

	while (len_b > 0)
	{
		pos_max = ft_locate_max(*tab_b, len_b);
		if (len_b > 1 && pos_max > len_b / 2)
		{
			while (pos_max < len_b)
			{
				ft_reverse(&tab_b[0], 'b', len_b);
				pos_max++;
			}
		}
		else if (len_b > 1)
		{
			while (pos_max > 0)
			{
				ft_rotate(&tab_b[0], 'b', len_b);
				pos_max--;
			}
		}
		ft_push(&tab_a[0], &tab_b[0], len_a++, 'a');
		ft_malloc_push(&tab_b[0], len_b--);
	}
}

static void	loop(int **stack_a, int **stack_b, int *len_a, int tracker)
{
	static int	len_b = 0;

	ft_push(&stack_b[0], &stack_a[0], len_b++, 'b');
	ft_malloc_push(&stack_a[0], len_a[0]--);
	if (stack_b[0][0] > (tracker))
		ft_rotate(&stack_b[0], 'b', len_b);
}

void	ft_butterfly(int **stack_a, int **stack_b, int chunk, int len_a)
{
	int	i;
	int	tracker ;
	int	number_elements_in_chunk;
	int	len;

	number_elements_in_chunk = len_a / chunk;
	tracker = number_elements_in_chunk;
	len = len_a;
	while (len_a > 0)
	{
		i = 0;
		while (i < number_elements_in_chunk && len_a > 0)
		{
			if (stack_a[0][0] < tracker)
			{
				loop(&stack_a[0], &stack_b[0], &len_a,
					(tracker - len / (chunk * 2)));
				i++;
			}
			else
				ft_rotate(&stack_a[0], 'a', len_a);
		}
		tracker += number_elements_in_chunk;
	}
}

void	call_fonction(int *tab_a, int *tab_b, int len_a)
{
	ft_normalisation(&tab_a, len_a);
	if (len_a > 100)
		ft_butterfly(&tab_a, &tab_b, 8, len_a);
	else if (len_a > 20)
		ft_butterfly(&tab_a, &tab_b, 4, len_a);
	else if (len_a > 5)
		ft_butterfly(&tab_a, &tab_b, 1, len_a);
	else if (len_a > 4)
		ft_sort_five(&tab_a, &tab_b, len_a);
	else if (len_a > 3)
		ft_sort_four(&tab_a, &tab_b, len_a);
	else if (len_a > 2)
		ft_sort_three(&tab_a, len_a);
	else if (len_a > 1)
		ft_swap(&tab_a, 'a');
	if (len_a > 5)
		ft_sort(&tab_a, &tab_b, 0, len_a);
	free(tab_a);
	if (tab_b)
		free(tab_b);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;
	int		*tab_a;
	int		*tab_b;

	i = 1;
	j = 0;
	tab_b = NULL;
	str = NULL;
	if (argc > 1)
	{
		while (i < argc)
			str = ft_strjoin(str, argv[i++]);
		j = ft_verif_int(str);
		tab_a = ft_split(str, ' ', &i);
		if (j == 1 || tab_a == NULL || ft_verif_repeat(tab_a, i))
		{
			error(tab_a);
			return (0);
		}
		if (!ft_order(tab_a, i) && i > 1)
			call_fonction(tab_a, tab_b, i);
	}
	return (0);
}
