/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundel_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:12:53 by rouali            #+#    #+#             */
/*   Updated: 2023/04/09 17:22:12 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	space_valid(char **av)
{
	int	x;
	int	y;
	int	z;

	x = -1;
	z = 0;
	while (av[++x])
	{
		if ((av[x][0] == ' ') || av[x][0] == '\0')
		{
			if (av[x][0] == ' ')
			{
				y = -1;
				while (av[x][++y])
					if (av[x][y] >= '0' && av[x][y] <= '9')
						z++;
				if (z > 0)
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
	int	len;

	di.x = 1;
	while (av[di.x])
	{
		di.y = 0;
		len = ft_strlen(av[di.x]);
		if (av[di.x][di.y] == '-')
			di.y++;
		while (di.y < len && av[di.x][di.y] == '0')
			di.y++;
		len = len - di.y;
		if (len > 10)
			ft_write_error();
		if ((ft_atoi(av[di.x]) > 2147483647 || ft_atoi(av[di.x]) < -2147483648))
			ft_write_error();
		di.x++;
	}
}

void	ft_duplicate(void)
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
				ft_write_error();
			y++;
		}
		x++;
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
