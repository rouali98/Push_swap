/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:14 by rouali            #+#    #+#             */
/*   Updated: 2023/04/10 16:51:35 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char *str, char c)
{
	int		x;
	int		y;
	int		save;
	char	*arg[(ft_word(str, c) + 1)];
	char	**ps;

	x = 0;
	y = 0;
	if (!str)
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
	ps = &arg[0];
	return (ps);
}

int	ft_contare(char **av)
{
	int		x;
	int		y;
	int		c;
	char	**split;

	x = 1;
	c = 0;
	while (av[x])
	{
		y = 0;
		split = ft_split(av[x], ' ');
		while (split[y++])
			c++;
		x++;
	}
	return (c);
}

int	*ft_arg(char **str)
{
	int		x;
	int		y;
	int		z;
	int		*arg;

	arg = malloc(sizeof(int *) * (ft_contare(str) + 1));
	if (!arg)
		return (0);
	x = 1;
	z = 0;
	while (str[x])
	{
		y = 0;
		while (ft_split(str[x], ' ')[y])
		{
			arg[z++] = ft_atoi(ft_split(str[x], ' ')[y]);
			y++;
		}
		x++;
	}
	return (arg);
}

void	sort(char **av)
{
	if (!stack_s.stackb)
		exit(1);
	if (ps.contare < 4)
		ft_sort_three();
	if (ps.contare > 3 && ps.contare <= 5)
		ft_sort_five();
	if (ps.contare > 5 && ps.contare <= 100)
		ft_sort_hundred(av);
	if (ps.contare > 100)
		ft_sort_fivehundred(av);
}

int	main(int ac, char **av)
{
	int	*arg;

	arg = ft_arg(av);
	if (ac <= 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_check_is_not_nbr(av);
	stack_s.stacka = arg;
	stack_s.stackb = malloc(sizeof(int) * (ps.sb + 1));
	if (!stack_s.stackb)
		return (0);
	ps.sb = 0;
	stack_s.stackb[0] = 0;
	ps.contare = ft_contare(av);
	space_valid(av);
	ft_int_max_min(av);
	ft_duplicate();
	ft_is_sorted();
	sort(av);
	free(stack_s.stackb);
	free(arg);
	return (0);
}
