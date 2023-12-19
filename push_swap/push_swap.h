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

void	ft_display(int	*tab_a, int	*tab_b, int len_a, int len_b);
int		ft_verif_order(int *src, int len_a, int len_b, int secu);
int		ft_verif_revers_order(int *src, int len);
int		ft_verif_first(int *src, int len);
int		ft_verif_int(char *src);
int		ft_atoi(char *src);
int		ft_len_tab(int *src);
char	*ft_malloc_str(char *src);
int		*ft_malloc_tab(int *src, int mal);
int		*ft_malloc_push(int *src, int len);
int		*ft_rotate_a(int *src, char c);
int		*ft_rotate_b(int *src);
int		*ft_reverse(int *src, char c, int len);
/* int 	*ft_reverse_b(int *src); */
int		*ft_swap(int *src, char c, int len);
int		*ft_push(int *src2, int *src1, char c, int len);
int		*ft_split(char *s, char c, int *len);
char	*ft_strjoin(char *s1, char *s2);
void	error(char *src);

#endif
