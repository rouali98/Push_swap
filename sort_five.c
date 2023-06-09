/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:08:59 by rouali            #+#    #+#             */
/*   Updated: 2023/04/14 16:15:08 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_nbr(void)
{
	int	min;

	di.x = 0;
	min = stack_s.stacka[0];
	while (di.x < ps.contare)
	{
		if (stack_s.stacka[di.x] < min)
			min = stack_s.stacka[di.x];
		di.x++;
	}
	return (min);
}

void	ft_pa_rra(void)
{
	int	min;
	int	x;

	x = 0;
	while (x < ps.contare)
	{	
		min = ft_min_nbr();
		if (stack_s.stacka[ps.contare - 1] == min)
		{
			ft_rev_a_shift_down();
			push_a();
			ps.contare--;
			break ;
		}
		if (stack_s.stacka[0] == min)
		{
			push_a();
			ps.contare--;
			break ;
		}
		else
			ft_rev_a_shift_up();
		x++;
	}
}

void	ft_sort_four(void)
{
	if (ps.contare == 4)
	{
		ft_pa_rra();
		ft_sort_three();
		push_b();
		ps.contare++;
	}
}

void	ft_sort_five(void)
{
	ft_sort_four();
	if (ps.contare == 5)
	{
		ft_pa_rra();
		ft_sort_four();
		push_b();
		ps.contare++;
	}
}
