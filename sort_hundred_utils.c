/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:07:05 by rouali            #+#    #+#             */
/*   Updated: 2023/04/08 21:35:39 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_range(int *arr, int save)
{
	ft_confined(arr, save);
	ft_smaller(arr, save);
	ft_larger(arr);
}

int	ft_mx(void)
{
	di.x = 0;
	di.max = stack_s.stackb[0];
	while (di.x < ps.sb)
	{
		if (stack_s.stackb[di.x] > di.max)
			di.max = stack_s.stackb[di.x];
		di.x++;
	}
	return (di.max);
}

int	ft_max_nbr(void)
{
	int	x;

	x = 0;
	di.max = 0;
	while (x < ps.sb)
	{
		if (stack_s.stackb[x] == ft_mx())
		{
			di.max = x;
			return (di.max);
		}
		x++;
	}
	return (0);
}

void	ft_return_sb(void)
{
	int	x;

	di.max = ft_max_nbr();
	di.med = ps.sb / 2;
	if (di.max > di.med)
	{
		x = ps.sb - 1;
		while (x-- >= di.max)
			ft_rev_b_shift_down();
	}
	else
	{
		x = 0;
		while (x++ < di.max)
			ft_rev_b_shift_up();
	}
	ps.contare++;
	push_b();
}
