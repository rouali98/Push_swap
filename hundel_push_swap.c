/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundel_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:12:53 by rouali            #+#    #+#             */
/*   Updated: 2023/04/08 22:07:30 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	space_valid(char **av)
{
	int	c;
	int	k;
	int	b;

	k = 0;
	c = -1;
	while (av[++c])
	{
		if ((av[c][0] == ' ') || av[c][0] == '\0')
		{
			if (av[c][0] == ' ')
			{
				b = -1;
				while (av[c][++b])
					if (av[c][b] >= '0' && av[c][b] <= '9')
						k++;
				if (k > 0)
					return ;
				else
					ft_write_error();
			}
			else
				ft_write_error();
		}
	}
}

void	ft_int_max_min(char **av)
{
	di.x = 1;
	while (av[di.x])
	{
		if ((ft_atoi(av[di.x]) > 2147483647 || ft_atoi(av[di.x]) < -2147483648))
			ft_write_error();
		di.x++;
	}
}

void	ft_duplicate(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps.contare)
	{
		j = 0;
		while (j < ps.contare)
		{
			if (stack_s.stacka[i] == stack_s.stacka[j] && i != j)
				ft_write_error();
			j++;
		}
		i++;
	}
}

void	ft_is_sorted(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < ps.contare)
	{
		if ((stack_s.stacka[x] > stack_s.stacka[x + 1]) && (x + 1) < ps.contare)
			y++;
		x++;
	}
	if (y == 0)
		exit (0);
}

void	ft_check_is_not_nbr(char **av)
{
	int		x;
	int		y;

	x = 1;
	while (av[x])
	{
		y = 0;
		while (av[x][y])
		{
			if ((av[x][y] >= '0' && av[x][y] <= '9') \
			|| (av[x][y] == '-' || av[x][y] == '+') || av[x][y] == ' ')
			{
				if ((av[x][y] == '-' || av[x][y] == '+') \
				&& (av[x][y - 1] != ' ') && y != 0)
					ft_write_error();
				y++;
			}
			else
				ft_write_error();
		}
		x++;
	}
}