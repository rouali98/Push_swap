/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:14 by rouali            #+#    #+#             */
/*   Updated: 2023/04/06 00:38:59 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ctype.h>

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

void free_db_ptr(char**ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
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
		free_db_ptr(split);
	}
	return (c);
}

int	*ft_arg(char **str)
{
	int		x;
	int		y;
	int		z;
	int		*arg;
	char	**split;

	x = 1;
	y = 0;
	z = 0;
	arg = malloc(sizeof(int) * (ps.contare + 1));
	if (!arg)
		exit(1);
	while (str[x])
	{
		y = 0;
		split = ft_split(str[x], ' ');
		while (split[y])
		{
			arg[z++] = ft_atoi(split[y++]);
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
	// while (1);
	if (ps.contare > 5 && ps.contare <= 100)
		ft_sort_hundred(av);
	if (ps.contare > 100)
		ft_sort_fivehundred(av);
}

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

int	main(int ac, char **av)
{
	if (ac <= 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_check_is_not_nbr(av);
	int *arg = ft_arg(av);
	stack_s.stacka = arg;
	// leaks here 8
	// while(1);
	stack_s.stackb = malloc(sizeof(int) * (ps.sb + 1));
	ps.sb = 0;
	stack_s.stackb[0] = 0;
	ps.contare = ft_contare(av);
	space_valid(av);
	ft_over(av);
	ft_duplicate();
	ft_is_sorted();
	sort(av);
	// while(1);
	// leaks here 2 //18
	return (0);
}
