/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:55 by rouali            #+#    #+#             */
/*   Updated: 2023/03/09 17:45:33 by rouali           ###   ########.fr       */
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

} ps;

struct s_direction
{
	int	x;
	int	y;
} di;

struct s_stack
{
	int	*stacka;
	int	*stackb;
} stack_s;

/* ################## Stack A ########################## */

void	ft_swap_first(char **av);
void	ft_rev_shift_up(char **av);
void	ft_rev_shift_down(char **av);
int		*push_a(int nbr, int *str, int contare);
//void	ft_ss(int contare);

/* ################## Stack B ########################## */

int	*push_b(int nbr, int *str, int contare);

/* ####################### MAIN ########################*/

int		ft_isdigit(int n);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_word(char *str, char c);
char	*ft_strndup(char *str, int n);
char	**ft_split(char *str, char c);
int		*ft_arg(char **str);
int		ft_contare(char **av);
#endif