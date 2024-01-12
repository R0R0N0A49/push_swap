/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:07:00 by trebours          #+#    #+#             */
/*   Updated: 2023/12/12 11:07:05 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *src)
{
	long	i;
	int		mult;
	int		rsl;

	rsl = 0;
	mult = 1;
	i = 0;
	if (src[0] == '-')
		mult = -1;
	if (src[0] == '-' || src[0] == '+')
		i++;
	while (src[i])
	{
		rsl = rsl * 10 + (src[i] - '0');
		i++;
	}
	rsl *= mult;
	return (rsl);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rsl;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (s1)
		i = ft_strlen(s1);
	rsl = malloc((i + ft_strlen(s2) + 2) * sizeof(char));
	if (rsl == 0)
		return (0);
	i = 0;
	while ((s1 && s1[i]))
	{
		rsl[i] = s1[i];
		i++;
	}
	rsl[i] = 0;
	ft_loop(&rsl, s2, &i, &j);
	rsl[i + j] = 0;
	if (s1)
		free(s1);
	return (rsl);
}

void	ft_malloc_push(int **src, int len)
{
	int	*result;
	int	i;
	int	j;

	result = malloc (len * sizeof(int));
	if (!result)
		return ;
	i = 1;
	j = 0;
	while (i < len)
	{
		result[j] = src[0][i];
		i++;
		j++;
	}
	free(src[0]);
	src[0] = result;
}

int	ft_locate_max(int *tab_b, int len)
{
	int	i;
	int	save;
	int	save_position;

	i = 0;
	save = 0;
	while (i < len)
	{
		if (save < tab_b[i])
		{
			save = tab_b[i];
			save_position = i;
		}
		i++;
	}
	return (save_position);
}

void	error(void *src)
{
	write (2, "Error\n", 6);
	free(src);
}
