/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:14 by rouali            #+#    #+#             */
/*   Updated: 2023/03/31 21:48:32 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char *str, char c)
{
	int		x;
	int		y;
	int		save;
	char	**arg;

	x = 0;
	y = 0;
	if (!str)
		return (0);
	arg = malloc(sizeof(char *) * (ft_word(str, c) + 1));
	if (!arg)
		return (0);
	while (x < ft_word(str, c) && str[y])
	{
		while (str[y] == c)
			y++;
		save = y;
		while (str[y] != c && str[y])
			y++;
		arg[x] = ft_strndup(&str[save], y - save);
		if (arg[x++] == 0)
			return (NULL);
	}
	arg[x] = 0;
	return (arg);
}

int	*ft_arg(char **str)
{
	int		x;
	int		y;
	int		z;
	int		*arg;

	x = 1;
	y = 0;
	z = 0;
	arg = malloc(sizeof(int *) * 100);
	if (!arg)
		exit(1);
	while (str[x])
	{
		while (ft_split(str[x], ' ')[y])
			arg[z++] = ft_atoi(ft_split(str[x], ' ')[y++]);
		y = 0;
		x++;
	}
	return (arg);
}

int	ft_contare(char **av)
{
	int	x;
	int	y;
	int	c;

	x = 1;
	c = 0;
	while (av[x])
	{
		y = 0;
		while (ft_split(av[x], ' ')[y++])
			c++;
		x++;
	}
	return (c);
}

void	sort(char **av)
{
	if (!stack_s.stackb)
		exit(1);
	if (ps.contare < 4)
		ft_sort_three();
	if (ps.contare > 3 && ps.contare < 6)
		ft_sort_five();
	if (ps.contare > 5 && ps.contare <= 100)
		ft_sort_hundred(av);
}

int	main(int ac, char **av)
{	
	if (ac <= 0)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	stack_s.stacka = ft_arg(av);
	ps.sb = 0;
	stack_s.stackb = malloc(sizeof(int) * (ps.sb + 1));
	stack_s.stackb[0] = 0;
	ps.contare = ft_contare(av);
	sort(av);
}
