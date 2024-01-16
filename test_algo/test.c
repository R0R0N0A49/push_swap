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
