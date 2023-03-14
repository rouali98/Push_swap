/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:55 by rouali            #+#    #+#             */
/*   Updated: 2023/03/12 15:07:46 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

struct s_push_swap
{
	char	*var;
	int		contare;
	int		fill;
	int		c;
} ps;

struct s_direction
{
	int	x;
	int	y;
	int	z;
} di;

struct s_stack
{
	int	*stacka;
	int	*stackb;
} stack_s;

/* ################## Stack A ########################## */

void	f_print(char *str);
void	ft_swap_a_first(char **av);
void	ft_rev_a_shift_up(char **av);
void	ft_rev_a_shift_down(char **av);
void	push_a(int nbr, int *str);

/* ################## Stack B ########################## */

void	ss(char **arg);
void	ft_swap_b_first(char **av);
void	ft_rev_b_shift_up(char **av);
void	ft_rev_b_shift_down(char **av);
void	push_b(int nbr, int *str);

/* #################### PUSH SWAP UTILIS #####################*/

int		ft_isdigit(int n);
long int		ft_atoi(const char *str);
int		ft_strlen(char *str);
char	*ft_strndup(char *str, int n);
int		ft_word(char *str, char c);

/* ################## SORT ##############################*/

void	ft_sort_three(char **av);
void	ft_sort_five(char **av);

/* ####################### MAIN ########################*/

int		ft_isdigit(int n);
int		ft_strlen(char *str);
int		ft_word(char *str, char c);
char	*ft_strndup(char *str, int n);
char	**ft_split(char *str, char c);
int		*ft_arg(char **str);
int		ft_contare(char **av);
void	sort(char **av);

#endif