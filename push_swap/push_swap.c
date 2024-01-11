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

void	ft_butterfly(int **stack_a, int **stack_b, int chunk, int len_a)
{
	int	i;
	int	tracker;
	int	number_elements_in_chunk;
	int	len_b;
	int	len;

	number_elements_in_chunk = len_a / chunk;
	tracker = number_elements_in_chunk;
	len_b = 0;
	len = len_a;
	while (len_a > 0)
	{
		i = 0;
		while (i < number_elements_in_chunk && len_a > 0)
		{
			if (stack_a[0][0] < tracker)
			{
				ft_push(&stack_b[0], &stack_a[0], len_b++, 'b');
				ft_malloc_push(&stack_a[0], len_a--);
				if (stack_b[0][0] > (tracker - len / (chunk * 2)))
					ft_rotate(&stack_b[0], 'b', len_b);
				i++;
			}
			else
				ft_rotate(&stack_a[0], 'a', len_a);
		}
		tracker += number_elements_in_chunk;
	}
}

void	ft_normalisation(int **a, int len_a)
{
	int	*save;
	int	*current;
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	current = a[0];
	save = malloc(len_a * sizeof(int));
	while (j < len_a)
	{
		i = 0;
		while (i < len_a)
		{
			if (a[0][j] > current[i])
				count++;
			i++;
		}
		save[j] = count;
		count = 0;
		j++;
	}
	free(a[0]);
	a[0] = save;
}

void	call_fonction(int *tab_a, int *tab_b, int len_a)
{
	if (ft_verif_repeat(tab_a, len_a))
	{
		error(tab_a);
		return ;
	}
	if (ft_order(tab_a, len_a) || len_a <= 1)
	{
		free(tab_a);
		return ;
	}
	ft_normalisation(&tab_a, len_a);
	if (len_a > 100)
		ft_butterfly(&tab_a, &tab_b, 8, len_a);
	else if (len_a > 12)
		ft_butterfly(&tab_a, &tab_b, 4, len_a);
	else
		ft_butterfly(&tab_a, &tab_b, 1, len_a);
	ft_sort(&tab_a, &tab_b, 0, len_a);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	int		*tab_a;
	int		*tab_b;

	i = 1;
	tab_b = NULL;
	str = NULL;
	if (argc > 1)
	{
		while (i < argc)
			str = ft_strjoin(str, argv[i++]);
		if (!ft_verif_int(str))
		{
			write (2, "Error\n", 6);
			/* error(str); */
			return (0);
		}
		tab_a = ft_split(str, ' ', &i);
		if (tab_a == NULL)
		{
			error(tab_a);
			return (0);
		}
		call_fonction(tab_a, tab_b, i);
	}
	return (0);
}
