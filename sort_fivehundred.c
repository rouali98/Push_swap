/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fivehundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:58:20 by rouali            #+#    #+#             */
/*   Updated: 2023/04/02 22:35:19 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_is_sorted(char **av)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (av[x])
	{
		if (av[x + 1] && (ft_atoi(av[x]) > ft_atoi(av[x + 1])))
			y++;
		x++;
	}
	if (y == 0)
		exit (0);
}

void	ft_duplicate(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps.contare)
	{
		j = i + 1;
		while (j < ps.contare)
		{
			if (stack_s.stacka[i] == stack_s.stacka[j])
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_over(char **av)
{
	di.x = 1;
	while (av[di.x])
	{
		if ((ft_atoi(av[di.x]) > 2147483647 || ft_atoi(av[di.x]) < -2147483648))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		di.x++;
	}
}

char	**args_with_no_space(char **str)
{
	int		x;
	int		y;
	int		z;
	char	**arg;

	x = 1;
	y = 0;
	z = 0;
	arg = malloc(sizeof(int *) * (ps.contare + 1));
	if (!arg)
		exit(1);
	while (str[x])
	{
		while (ft_split(str[x], ' ')[y])
		{
			arg[z++] = ft_split(str[x], ' ')[y++];
		}
		y = 0;
		x++;
	}
	return (arg);
}

void	ft_check_is_not_nbr(char **av)
{
	int x;
	int y;
	
	char **arg = args_with_no_space(av);
	x = 1;
	while (arg[x])
	{
		y = 0;
		while (arg[x][y])
		{printf("hhhh");
			if ((arg[x][y] >= '0' && arg[x][y] <= '9') || (arg[x][y] == '-') || (arg[x][y] == '+'))
			{
				if (arg[x][y] == '-' || arg[x][y] == '+')
				{
					
					if (y != 0)
					{
						write(1, "Error\n", 6);
						exit(1);
					}
				}
				y++;
			}
			else
			{
				write(1, "Errorr\n", 6);
				exit(1);
			}
		}
		x++;
	}
}

void	ft_sort_fivehundred(char **av)
{
	int	*arr;
	int	save;

	ft_duplicate();
	arr = ft_arrange(av);
	save = ps.contare - 1;
	di.start = 0;
	di.end = 35;
	if (di.end > save)
		di.end = save;
	while (ps.contare)
	{
		ft_range(arr, save);
	}
	while (ps.sb)
	{
		ft_return_sb();
	}
}
