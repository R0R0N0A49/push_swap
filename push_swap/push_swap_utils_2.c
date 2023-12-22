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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rsl;
	int		j;
	int		i;

	j = 0;
	i = 0;
	rsl = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (rsl == 0)
		return (0);
	while ((s1 && s1[i]))
	{
		rsl[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		rsl[i + j] = s2[j];
		j++;
	}
	rsl[i + j] = ' ';
	rsl[i + j + 1] = '\0';
	if (s1)
		free(s1);
	return (rsl);
}

void	error(char *src)
{
	write (2, "Error\n", 6);
	free(src);
}
