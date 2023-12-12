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

char	**ft_malloc_first_tab(char **src)
{
	int		i;
	char	**result;

	i = 0;
	result = malloc((ft_len_tab(src) + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (src[i])
	{
		result[i] = ft_malloc_str(src[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}

char **ft_malloc_push(char **src)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	len = ft_len_tab(src);
	if ((len - 1) == 0)
	{
		ft_free(src);
		return (NULL);
	}
	/* juste le taille du tab vu que (tab - 1) */
	result = malloc (ft_len_tab(src) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 1;
	j = 0;
	free(src[0]);
	while (src[i])
	{
		result[j] = ft_malloc_str(src[i]);
		free(src[i]);
		i++;
		j++;
	}
	result[j] = 0;
	free(src);
	return (result);
}

void	ft_push_swap(char **tab_a)
{
	char	**tab_b;

	tab_b = NULL;
	while (ft_verif_order(tab_a, tab_b, 1))
	{
		while (ft_verif_order(tab_a, tab_b, 0))
		{
			if (ft_verif_first(tab_a) == 1)
				tab_a = ft_rotate_a(tab_a);
			else if (ft_verif_first(tab_a) == -1)
				tab_a = ft_reverse_a(tab_a);
			else if (ft_atoi(tab_a[0]) > ft_atoi(tab_a[1]))
				tab_a = ft_swap(tab_a, 'a');
			else
			{
				tab_b = ft_push(tab_b, tab_a, 'a');
				tab_a = ft_malloc_push(tab_a);
				ft_display(tab_a, tab_b);
			}
		}
		/*a metre dans une autre fonction : */ 
		if (tab_b)
		{			
			tab_a = ft_push(tab_a, tab_b, 'b');
			tab_b = ft_malloc_push(tab_b);
		}
		ft_display(tab_a, tab_b);
	}
	if (tab_b)
		ft_free(tab_b);
	ft_free(tab_a);
	
}

int	main(int argc, char **argv)
{
	int		i;
	char	**tab_a;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (!ft_verif_int(argv[i]))
			{
				ft_error();
				return (0);
			}
			i++;
		}
		tab_a = ft_malloc_first_tab(&argv[1]);
		ft_display(tab_a, NULL);
		ft_push_swap(tab_a);
	}
	return (0);
}
