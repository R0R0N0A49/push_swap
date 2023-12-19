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



int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	int		*tab_a;

	i = 1;
	str = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			str = ft_strjoin(str, argv[i]);
			i++;
		}
		if (!ft_verif_int(str))
		{
			error(str);
			return (0);
		}
		tab_a = ft_split(str, ' ', &i);
		ft_push_swap(tab_a, i);
	}
	return (0);
}
