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

void	ft_display(int	*tab_a, int	*tab_b, int len_a, int len_b)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	ft_printf("\n_______________________________________\n\n");
	while (i < len_a || j < len_b)
	{
		if ((i >= len_a && len_a >= 0) || (j >= len_b && len_a <= 0))
			ft_printf("%d\t%d\n", tab_a[i], tab_b[j]);
		else if (len_a > 0)
			ft_printf("%d\t \n", tab_a[i]);
		else if (len_b > 0)
			ft_printf(" \t%d\n", tab_b[j]);
		if ((i >= len_a || (j >= len_b && len_a < 0)) && tab_b[j])
			j++;
		if ((len_a > 0) || ((j > len_b) && tab_a[i]))
			i++;
	}
	ft_printf("a\tb\n_______________________________________\n\n");
}
