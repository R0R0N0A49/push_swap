/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:00 by trebours          #+#    #+#             */
/*   Updated: 2023/12/08 14:47:05 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(int **src, char c, int len)
{
	int	tmp;
	int	i;

	tmp = src[0][0];
	i = 1;
	while (i < len)
	{
		src[0][i - 1] = src[0][i];
		i++;
	}
	src[0][len - 1] = tmp;
	if (c != '\0')
		ft_printf("r%c\n", c);
}

void	ft_rr(int **tab_a, int **tab_b, int len_a, int len_b)
{
	ft_rotate(&tab_a[0], '\0', len_a);
	ft_rotate(&tab_b[0], '\0', len_b);
	ft_printf("rr\n");
}

void	ft_reverse(int **src, char c, int len)
{
	int	tmp;
	int	i;

	tmp = src[0][0];
	src[0][0] = src[0][len - 1];
	i = len - 1;
	while (i > 1)
	{
		src[0][i] = src[0][i - 1];
		i--;
	}
	src[0][i] = tmp;
	if (c != '\0')
		ft_printf("rr%c\n", c);
}

void	ft_rrr(int **tab_a, int **tab_b, int len_a, int len_b)
{
	ft_reverse(&tab_a[0], '\0', len_a);
	ft_reverse(&tab_b[0], '\0', len_b);
	ft_printf("rrr\n");
}
