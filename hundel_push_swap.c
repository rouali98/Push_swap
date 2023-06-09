/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundel_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:12:53 by rouali            #+#    #+#             */
/*   Updated: 2023/04/14 01:08:27 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	space_valid(char **av)
{
	int	c;
	int	b;

	di.x = 0;
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
						di.x++;
				if (di.x > 0)
					return (0);
				else
					return (1);
			}
			else
				return (1);
		}
	}
	return (0);
}

int	ft_duplicate(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < ps.contare)
	{
		y = 0;
		while (y < ps.contare)
		{
			if (stack_s.stacka[x] == stack_s.stacka[y] && x != y)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	ft_is_sorted(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < ps.contare)
	{
		if ((x + 1) < ps.contare && (stack_s.stacka[x] > stack_s.stacka[x + 1]))
			y++;
		x++;
	}
	if (y == 0)
		return (1);
	return (0);
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
					ft_exit_error();
				y++;
			}
			else
				ft_exit_error();
		}
		x++;
	}
}
