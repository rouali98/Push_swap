/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:55 by rouali            #+#    #+#             */
/*   Updated: 2023/04/02 22:19:37 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct s_push_swap
{
	char	*var;
	int		contare;
	int		fill;
	int		c;
	int		sb;
} ps;

struct s_direction
{
	int	x;
	int	y;
	int	z;
	int	start;
	int	end;
	int	max;
	int	med;
} di;

struct s_stack
{
	int	*stacka;
	int	*stackb;
} stack_s;

/* ################## Stack A ########################## */

void	f_print(char *str);
void	ft_swap_a_first(void);
void	ft_rev_a_shift_up(void);
void	ft_rev_a_shift_down(void);
void	push_a(void);

/* ################## Stack B ########################## */

void	ss(void);
void	ft_swap_b_first(void);
void	ft_rev_b_shift_up(void);
void	ft_rev_b_shift_down(void);
void	push_b(void);
void	f_printp(char *str);

/* #################### PUSH SWAP UTILIS #####################*/

int		ft_isdigit(char *str);
long	ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_strndup(char *str, int n);
int		ft_word(char *str, char c);

/* ################## SORT ##############################*/

void	ft_sort_three(void);
void	ft_sort_five(void);
void	ft_sort_hundred(char **av);
void	ft_sort_fivehundred(char **av);
int		ft_min(void);
void	ft_pa_rra(void);
void	ft_confined(int *arr, int save);
void	ft_smaller(int *arr, int save);
void	ft_larger(int *arr);
int		*ft_arrange(char **av);
void	ft_range(int *arr, int save);
int		ft_max(void);
void	ft_return_sb(void);
void	ft_over(char **av);
void	ft_duplicate(void);
void	ft_is_sorted(char **av);
char	**args_with_no_space(char **str);

/* ####################### MAIN ########################*/

int		ft_strlen(char *str);
int		ft_word(char *str, char c);
char	*ft_strndup(char *str, int n);
char	**ft_split(char *str, char c);
int		*ft_arg(char **str);
int		ft_contare(char **av);
void	space_valid(char **av);
void	sort(char **av);
void	ft_check_is_not_nbr(char **av);

#endif