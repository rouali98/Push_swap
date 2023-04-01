/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fivehundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:58:20 by rouali            #+#    #+#             */
/*   Updated: 2023/04/01 02:13:26 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_fivehundred(char **av)
{
    int	*arr;
	int	save;
	int	max;
	int	med;
	int x;

	x = 0;
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
		max = ft_max();
		med = ps.sb / 2;
		if (max > med)
		{
			x = ps.sb - 1;
			while (x >= max)
			{
				ft_rev_b_shift_down();
				f_print("rrb");
				x--;
			}
		}
		else
		{
			x = 0;
			while (x < max)
			{
				ft_rev_b_shift_up();
				f_print("rb");
				x++;
			}
		}
		ps.contare++;
		push_b();
	}
}