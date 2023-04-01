/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fivehundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:58:20 by rouali            #+#    #+#             */
/*   Updated: 2023/04/01 22:13:39 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				write(1, "Error\nDuplicate number", 22);
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
			write(1, "Error\n", 7);
			exit(1);
		}
		di.x++;
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
	di.end = 25;
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
