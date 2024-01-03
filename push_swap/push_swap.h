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

int		*ft_push(int *src1, int *src2, int len, char c);
int		*ft_reverse(int *src, char c, int len);
int		*ft_rotate(int *src, char c, int len);
int		*ft_split(char *s, char c, int *len);
int		*ft_swap(int *src, char c);
int		*ft_malloc_push(int *src, int len);
int		*ft_malloc_tab(int *src, int mal);
int		ft_verif_first(int *src, int len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_verif_int(char *src);
int		ft_len_tab(int *src);
int		ft_atoi(char *src);
void	error(char *src);

int		ft_verif_revers(int *src, int len);
void	algo_for_ten(int *tab_a, int len_a);
void	ft_end(int **tab_a, int **tab_b, int len_a, int len_b);
int		ft_order(int *tab_a, int len_a, int len_b, int secu);
int		ft_order_reverse(int *tab_b, int len_b);
int		*ft_sort_2(int *tab_b, int len);
int		*ft_sort_1(int *tab_b, int len);
int		ft_average(int	*tab_a, int len_chunk, int len);
int		ft_verif_test(int len_chunk, int *tab_a, int *tab_b, int len_a);
void	ft_display(int	*tab_a, int	*tab_b, int len_a, int len_b);

#endif
