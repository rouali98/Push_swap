/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:22:31 by rouali            #+#    #+#             */
/*   Updated: 2023/03/21 19:39:54 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_hundred(void)
{
	int	i;
	int	min;

	i = 0;
	di.x = 0;
	min = stack_s.stacka[0];
	while (di.x < ps.contare)
	{
		if (stack_s.stacka[di.x] < min)
		{
			min = stack_s.stacka[di.x];
		}
		di.x++;
	}
	i++;
	return (min);
}

void	ft_pa_rra_hundred(void)
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

void	ft_sort_hundred(void)
{
	int	i = 0;

	while (i <= 5)
	{
		ft_pa_rra();
		i++;
	}
	ps.contare = ps.contare + 1;
}
