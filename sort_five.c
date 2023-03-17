/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:08:59 by rouali            #+#    #+#             */
/*   Updated: 2023/03/17 20:28:40 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void rra_1(char **av)
//{
//	if(stack_s.stacka[1] < stack_s.stacka[3])
//	{
//		ft_rev_a_shift_down();
//		f_print("rra");
//		//push_a(stack_s.stacka[0], stack_s.stackb);
//	}

//}
//void rra_2(char **av)
//{
//	if(stack_s.stacka[0] < stack_s.stacka[3])
//	{
//		ft_rev_a_shift_down();
//		f_print("rra");
//		//push_a(stack_s.stacka[0], stack_s.stackb);
//	}
//}

#include <limits.h>

void	ft_sort_five(void)
{
	//int i = 0;
	//if (ps.contare == 4)
	//{
	//		if(stack_s.stacka[0] < stack_s.stacka[3] && stack_s.stacka[0] < stack_s.stacka[2])
	//		{
	//			while (i < 1)
	//			{
	//				if(stack_s.stacka[0] < stack_s.stacka[3])
	//				{
	//					printf("1\n");
	//					ft_rev_a_shift_down(av);
	//					f_print("rra");
	//					//push_a(stack_s.stacka[0], stack_s.stackb);
	//				}
	//			i++;
	//			}
	//		}
	//}
	int i = 0;
	int min = stack_s.stacka[0];

	while (i < ps.contare)
	{
		if (stack_s.stacka[i] < min)
		{
			min = stack_s.stacka[i];
		}
		i++;
	}
	int pshkh = 0;
	while (pshkh < ps.contare) {
		if (stack_s.stacka[0] == min) {
			push_a(stack_s.stackb);
		}else {
			ft_rev_a_shift_down();
		}
		pshkh++;
	}
	ft_sort_three();
	push_b(stack_s.stacka);
	printf("min = %d", min);
}
