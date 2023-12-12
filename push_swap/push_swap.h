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

void	ft_error(void);
void	ft_display(char **tab_a, char **tab_b);
int		ft_verif_order(char **src, char **verif, int secu);
int		ft_verif_first(char **src);
int		ft_verif_int(char *src);
void	ft_free(char **src);
int		ft_atoi(char *src);
int		ft_len_tab(char **src);
char	*ft_malloc_str(char *src);
char	**ft_malloc_tab(char **src, int mal);
char	**ft_reverse_a(char **src);
char	**ft_reverse_b(char **src);
char	**ft_rotate_b(char **src);
char	**ft_rotate_a(char **src);
char	**ft_swap(char **src, char c);
char	**ft_push(char **src2, char **src1, char c);

#endif
