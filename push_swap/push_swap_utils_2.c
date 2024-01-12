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

void	ft_loop(char **rsl, char *s2, int *i, int *j)
{
	if (rsl[0] && rsl[0][i[0]] != ' ')
		rsl[0][i[0]++] = ' ';
	if (s2[0] == ' ' && (s2[1] >= '0' && s2[1] <= '9'))
	{
		i[0]--;
		j[0]++;
	}
	while (s2 && s2[j[0]])
	{
		if (s2[j[0]] == ' ' && (s2[j[0] + 1] == ' ' || s2[j[0] + 1] == '\0'))
		{
			i[0]--;
			j[0]++;
		}
		else
		{
			rsl[0][i[0] + j[0]] = s2[j[0]];
			j[0]++;
		}
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

void	ft_sort_three(int **stack_a, int len_a)
{
	while (stack_a[0][0] != 0 || stack_a[0][2] != 2)
	{
		if (stack_a[0][0] == 2)
			ft_rotate(&stack_a[0], 'a', len_a);
		if (stack_a[0][2] == 1 || stack_a[0][2] == 0)
			ft_reverse(&stack_a[0], 'a', len_a);
		if (stack_a[0][0] > stack_a[0][1])
			ft_swap(&stack_a[0], 'a');
	}
}

void	ft_sort_four(int **stack_a, int **stack_b, int len_a)
{
	int	len_b;

	len_b = 0;
	while (stack_a[0][0] != 0 || stack_a[0][1] != 1 | stack_a[0][3] != 3)
	{
		while (len_a > 2)
		{
			if (stack_a[0][0] == 0 || stack_a[0][0] == 1)
			{
				ft_push(&stack_b[0], &stack_a[0], len_b++, 'b');
				ft_malloc_push(&stack_a[0], len_a--);
			}
			else
				ft_rotate(&stack_a[0], 'a', len_a);
		}
		if (stack_b[0][0] == 0)
			ft_swap(&stack_b[0], 'b');
		if (stack_a[0][0] == 3)
			ft_swap(&stack_a[0], 'a');
		while (len_b > 0)
		{
			ft_push(&stack_a[0], &stack_b[0], len_a++, 'a');
			ft_malloc_push(&stack_b[0], len_b--);
		}
	}
}

void	ft_sort_five(int **stack_a, int **stack_b, int len_a)
{
	int	len_b;

	len_b = 0;
	while (len_b < 2)
	{
		if (stack_a[0][0] == 3 || stack_a[0][0] == 4)
		{
			ft_push(&stack_b[0], &stack_a[0], len_b++, 'b');
			ft_malloc_push(&stack_a[0], len_a--);
		}
		else
			ft_rotate(&stack_a[0], 'a', len_a);
	}
	ft_sort_three(&stack_a[0], len_a);
	if (stack_b[0][0] == 4)
		ft_swap(&stack_b[0], 'b');
	while (len_b > 0)
	{
		ft_push(&stack_a[0], &stack_b[0], len_a++, 'a');
		ft_malloc_push(&stack_b[0], len_b--);
		ft_rotate(&stack_a[0], 'a', len_a);
	}
}
