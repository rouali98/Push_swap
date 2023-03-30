/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:19:15 by rouali            #+#    #+#             */
/*   Updated: 2023/03/29 14:26:19 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_sa(void)
{
	if (stack_s.stacka[0] < stack_s.stacka[1] \
	&& stack_s.stacka[2] < stack_s.stacka[1])
	{
		if (stack_s.stacka[2] < stack_s.stacka[0])
		{
			ft_rev_a_shift_down();
			f_print("rra");
		}
		else if (stack_s.stacka[0] < stack_s.stacka[2])
		{
			ft_rev_a_shift_down();
			f_print("rra");
			ft_swap_a_first();
			f_print("sa");
		}
	}
}

void	ft_ra_sa(void)
{
	if (stack_s.stacka[1] < stack_s.stacka[0] \
	&& stack_s.stacka[2] < stack_s.stacka[0])
	{
		if (stack_s.stacka[1] < stack_s.stacka[2])
		{
			ft_rev_a_shift_up();
			f_print("ra");
		}
		if (stack_s.stacka[2] < stack_s.stacka[1])
		{
			ft_rev_a_shift_up();
			f_print("ra");
			ft_swap_a_first();
			f_print("sa");
		}
	}
}

void	ft_sort_three(void)
{
	if (ps.contare == 2)
	{
		if (stack_s.stacka[1] < stack_s.stacka[0])
		{
			ft_swap_a_first();
			f_print("sa");
		}
		return ;
	}
	ft_rra_sa();
	ft_ra_sa();
	if (stack_s.stacka[1] < stack_s.stacka[0] \
	&& stack_s.stacka[1] < stack_s.stacka[2])
	{
		if (stack_s.stacka[0] < stack_s.stacka[2])
		{
			ft_swap_a_first();
			f_print("sa");
		}
	}
}
