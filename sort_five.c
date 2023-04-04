/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:08:59 by rouali            #+#    #+#             */
/*   Updated: 2023/04/03 17:19:15 by rouali           ###   ########.fr       */
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
	while (ph < ps.contare)
	{	
		min = ft_min();
		if (stack_s.stacka[ps.contare - 1] == min)
		{
			ft_rev_a_shift_down();
			push_a();
			ps.contare = ps.contare - 1;
			break ;
		}
		if (stack_s.stacka[0] == min)
		{
			push_a();
			ps.contare = ps.contare - 1;
			break ;
		}
		else
			ft_rev_a_shift_up();
		ph++;
	}
}

void	ft_sort_four(void)
{
	if (ps.contare == 4)
	{
		ft_pa_rra();
		ft_sort_three();
		push_b();
		ps.contare = ps.contare + 1;
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
		ps.contare = ps.contare + 1;
	}
}
