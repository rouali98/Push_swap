/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:08:59 by rouali            #+#    #+#             */
/*   Updated: 2023/03/31 21:01:41 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(void)
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
	int	ph;

	ph = 0;
	min = ft_min();
	while (ph < ps.contare)
	{
		if (stack_s.stacka[0] == min)
		{
			push_a();
			ps.contare = ps.contare - 1;
			break ;
		}
		else
		{
			ft_rev_a_shift_down();
			f_print("rra");
		}
		ph++;
	}
}

void	ft_sort_five(void)
{
	if (ps.contare == 4)
	{
		ft_pa_rra();
		ft_sort_three();
		push_b();
		ps.contare = ps.contare + 1;
	}
	if (ps.contare == 5)
	{
		ft_pa_rra();
		ft_pa_rra();
		ft_sort_three();
		push_b();
		ps.contare = ps.contare + 1;
		push_b();
		ps.contare = ps.contare + 1;
	}
}
