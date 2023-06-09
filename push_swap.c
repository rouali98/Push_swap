/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:14 by rouali            #+#    #+#             */
/*   Updated: 2023/04/13 21:05:20 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_arg(char **av)
{
	int		x;
	int		y;
	int		z;
	int		*arg;

	arg = malloc(sizeof(int *) * (ft_contare(av)));
	if (!arg)
		return (0);
	x = 0;
	z = 0;
	while (av[++x])
	{
		y = 0;
		while (av[x][y])
		{
			while (av[x][y] == ' ' && av[x][y] != '\0')
				y++;
			if (av[x][y] == '\0')
				break ;
			arg[z++] = ft_atoi(&av[x][y]);
			while (av[x][y] != ' ' && av[x][y] != '\0')
				y++;
		}
	}
	return (arg);
}

void	sort(char **av)
{
	if (ps.contare < 4)
		ft_sort_three();
	if (ps.contare > 3 && ps.contare <= 5)
		ft_sort_five();
	if (ps.contare > 5 && ps.contare <= 100)
		ft_sort_hundred(av);
	if (ps.contare > 100)
		ft_sort_fivehundred(av);
}

void	ft_free_error(char **av)
{
	if (space_valid(av) == 1)
	{
		write(2, "Error\n", 6);
		ft_free_all();
		exit(1);
	}
	if (ft_duplicate() == 1)
	{
		ft_free_all();
		exit(1);
	}
	if (ft_is_sorted() == 1)
	{
		ft_free_all();
		exit(0);
	}
}

void	ft_push_swap(char **av)
{
	ps.arg = ft_arg(av);
	ft_check_is_not_nbr(av);
	stack_s.stacka = ps.arg;
	stack_s.stackb = malloc(sizeof(int) * (ps.sb + 1));
	if (!stack_s.stackb)
		return ;
	ps.sb = 0;
	stack_s.stackb[0] = 0;
	ps.contare = ft_contare(av);
	ft_free_error(av);
	sort(av);
	ft_free_all();
}

int	main(int ac, char **av)
{
	if (ac > 1)
		ft_push_swap(av);
	else
		return (0);
}
