/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:22:13 by trebours          #+#    #+#             */
/*   Updated: 2023/12/08 13:22:19 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "ft_printf/ft_printf.h"

void	ft_normalisation(int **a, int len_a);
void	ft_butterfly(int **stack_a, int **stack_b, int chunk, int len_a);
void	ft_sort(int **tab_a, int **tab_b, int len_a, int len_b);
void	ft_push(int **src1, int **src2, int len, char c);
void	ft_rotate(int **src, char c, int len);
void	ft_reverse(int **src, char c, int len);
void	ft_rr(int **tab_a, int **tab_b, int len_a, int len_b);
void	ft_rrr(int **tab_a, int **tab_b, int len_a, int len_b);
int		*ft_split(char *s, char c, int *len);
void	ft_malloc_push(int **src, int len);
long	ft_atoi(char *src);
int		ft_locate_max(int *tab_b, int len);
void	error(void *src);
char	*ft_strjoin(char *s1, char *s2);
void	ft_swap(int **src, char c);
void	ft_ss(int **tab_a, int **tab_b);
int		ft_verif_int(char *src);
void	ft_loop(char **rsl, char *s2, int *i, int *j);
int		ft_order(int *tab_a, int len_a);
int		ft_verif_repeat(int *tab_a, int len_a);
int		ft_atol(char *s, char c);
void	ft_normalisation(int **a, int len_a);
void	ft_sort_three(int **stack_a, int len_a);
void	ft_sort_four(int **stack_a, int **stack_b, int len_a);
void	ft_sort_five(int **stack_a, int **stack_b, int len_a);

#endif
