/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:19:15 by rouali            #+#    #+#             */
/*   Updated: 2023/03/11 19:19:43 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(char **av)
{
	if (ps.contare == 1)
	{
		printf("%d\n", stack_s.stacka[0]);
	}
	if (ps.contare == 2)
	{
		if (stack_s.stacka[1] < stack_s.stacka[0])
		{
			ft_swap_a_first(av);
			f_print("sa");
		}
		if (stack_s.stacka[0] < stack_s.stacka[1])
		{
			di.x = 0;
			while (di.x < ps.contare)
			{
				printf("%2d \n", stack_s.stacka[di.x]);
				di.x++;
			}
			write(1, " _  _\n", 6);
			write(1, " a  b\n", 6);
		}
		return ;
	}
	if (stack_s.stacka[0] < stack_s.stacka[1] && stack_s.stacka[0] < stack_s.stacka[2])
	{
		if (stack_s.stacka[1] < stack_s.stacka[2])
		{
			di.x = 0;
			while (di.x < ps.contare)
			{
				printf("%2d \n", stack_s.stacka[di.x]);
				di.x++;
			}
			write(1, " _  _\n", 6);
			write(1, " a  b\n", 6);
		}
	}
	 if (stack_s.stacka[0] < stack_s.stacka[1] && stack_s.stacka[2] < stack_s.stacka[1])
	{
		if (stack_s.stacka[2] < stack_s.stacka[0])
		{
			ft_rev_a_shift_down(av);
			f_print("rra");
		}
		if (stack_s.stacka[0] < stack_s.stacka[2])
		{
			ft_rev_a_shift_down(av);
			f_print("rra");
			ft_swap_a_first(av);
			f_print("sa");
		}
	}
	if (stack_s.stacka[1] < stack_s.stacka[0] && stack_s.stacka[2] < stack_s.stacka[0])
	{
		if (stack_s.stacka[1] < stack_s.stacka[2])
		{
			ft_swap_a_first(av);
			f_print("sa");
			ft_rev_a_shift_up(av);
			f_print("ra");
		}
		if (stack_s.stacka[2] < stack_s.stacka[1])
		{
			ft_rev_a_shift_up(av);
			f_print("ra");
			ft_swap_a_first(av);
			f_print("sa");
		}
	}
	if (stack_s.stacka[1] < stack_s.stacka[0] && stack_s.stacka[1] < stack_s.stacka[2])
	{
		if (stack_s.stacka[0] < stack_s.stacka[2])
		{
			ft_swap_a_first(av);
			f_print("sa");
		}
	}
	//ft_swap_a_first(arg);
	//f_print("sa");
	//ft_swap_b_first(arg);
	//f_print("sb");
	//ft_rev_a_shift_up(arg);
	//f_print("ra");
	//ft_rev_b_shift_up(arg);
	//f_print("rb");
	//ft_rev_a_shift_down(arg);
	//f_print("rra");
	//ft_rev_b_shift_down(arg);
	//f_print("rrb");
	//ss(arg);
	//f_print("ss");
	//push_a(stack_s.stacka[0], stack_s.stackb);
	//push_b(stack_s.stackb[0], stack_s.stacka);
}
