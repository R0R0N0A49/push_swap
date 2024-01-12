/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:48 by trebours          #+#    #+#             */
/*   Updated: 2023/12/08 14:47:50 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int **src, char c)
{
	int	tmp;

	tmp = src[0][0];
	src[0][0] = src[0][1];
	src[0][1] = tmp;
	if (c != '\0')
		ft_printf("s%c\n", c);
}

void	ft_ss(int **tab_a, int **tab_b)
{
	ft_swap(&tab_a[0], '\0');
	ft_swap(&tab_b[0], '\0');
	ft_printf("ss\n");
	return ;
}
