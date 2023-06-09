/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:47:05 by rouali            #+#    #+#             */
/*   Updated: 2023/04/14 01:52:54 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] >= '0' && str[x] <= '9')
			return (1);
		x++;
	}
	return (0);
}

int	ft_contare(char **av)
{
	int		x;
	int		y;
	int		z;
	char	*splt;

	x = 1;
	z = 0;
	while (av[x])
	{
		y = 0;
		splt = av[x];
		while (splt[y])
		{
			while (splt[y] == ' ' && splt[y] != '\0')
				y++;
			if (splt[y] == '\0')
				break ;
			z++;
			while (splt[y] != ' ' && splt[y] != '\0')
				y++;
		}
		x++;
	}
	return (z);
}

long	ft_atoi(char *str)
{
	int			x;
	int			y;
	long		result;

	x = 0;
	y = 1;
	result = 0;
	if ((str[0] == '-' && str[1] == '\0') || (str[0] == '+' && str[1] == '\0'))
		ft_exit_error();
	while (str[x] == 32 || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			y = y * -1;
		x++;
	}
	while ((str[x] >= '0' && str[x] <= '9') && str[x])
	{
		result = (result * 10) + (str[x] - '0');
		if ((result * y) > 2147483647 || (result * y) < -2147483648)
			ft_exit_error();
		x++;
	}
	return (result * y);
}
