/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:24:35 by trebours          #+#    #+#             */
/*   Updated: 2023/12/08 13:24:37 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (2, "(Error)\n", 8);
}

int	ft_len_tab(char **src)
{
	int	i;

	if (!src || (src && !src[0]))
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_display(char **tab_a, char **tab_b)
{
	int	i;
	int	j;
	int	len;
	int	len_b;

	j = 0;
	i = 0;
	len = ft_len_tab(tab_a) - ft_len_tab(tab_b);
	len_b = ft_len_tab(tab_b) - ft_len_tab(tab_a);
	ft_printf("\n_______________________________________\n\n");
	while ((tab_a && tab_a[i]) || (tab_b && tab_b[j]))
	{
		if ((i >= len && len >= 0) || (j >= len_b && len <= 0))
			ft_printf("%s\t%s\n", tab_a[i], tab_b[j]);
		else if (len > 0)
			ft_printf("%s\t \n", tab_a[i]);
		else if (len_b > 0)
			ft_printf(" \t%s\n", tab_b[j]);
		if ((i >= len || (j >= len_b && len < 0)) && tab_b[j])
			j++;
		if ((i >= len && len > 0) || (j > len_b) && tab_a[i])
			i++;
	}
	ft_printf("a\tb\n_______________________________________\n\n");
}
