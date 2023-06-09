/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:55 by rouali            #+#    #+#             */
/*   Updated: 2023/04/14 16:09:47 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct s_push_swap
{
	int		contare;
	int		fill;
	int		c;
	int		sb;
	int		*arg;
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

/* ################## HUNDEL_P_S ############################## */

int		space_valid(char **av);
int		ft_duplicate(void);
int		ft_is_sorted(void);
void	ft_check_is_not_nbr(char **av);

/* #################### PUSH SWAP UTILIS ##################### */

void	ft_exit_error(void);
long	ft_atoi(char *str);

/* ####################### PUSH SWAP ######################## */

int		ft_contare(char **av);
int		*ft_arg(char **str);

/* ################## SORT ############################## */

void	ft_sort_three(void);
void	ft_sort_five(void);
void	ft_sort_hundred(char **av);
void	ft_sort_fivehundred(char **av);

/* ################## Stack A ########################## */

void	ft_free_all(void);
void	ft_swap_a_first(void);
void	ft_rev_a_shift_up(void);
void	ft_rev_a_shift_down(void);
void	push_a(void);

/* ################## Stack B ########################## */

void	ft_swap_b_first(void);
void	ft_rev_b_shift_up(void);
void	ft_rev_b_shift_down(void);
void	push_b(void);

/* ################## SORT_HUNDRED_UTILS ##############################*/

void	ft_range(int *arr, int save);
void	ft_return_sb(void);

/* ################## SORT_HUNDRED ##############################*/

int		*ft_arrange(char **av);
void	ft_confined(int *arr, int save);
void	ft_smaller(int *arr, int save);
void	ft_larger(int *arr);

#endif