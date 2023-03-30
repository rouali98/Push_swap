/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:22:31 by rouali            #+#    #+#             */
/*   Updated: 2023/03/30 16:23:14 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_arrange(char **av)
{
	int	key;
	int	*arr;

	arr = ft_arg(av);
	ps.contare = ft_contare(av);
	di.x = 1;
	while (di.x < ps.contare)
	{
		key = arr[di.x];
		di.y = di.x - 1;
		while (di.y >= 0 && arr[di.y] > key)
		{
			arr[di.y + 1] = arr[di.y];
			di.y = di.y - 1;
		}
		arr[di.y + 1] = key;
		di.x++;
	}
	return (arr);
}

void ft_sort_hundred(char **av)
{
	int	x;
	int	start;
	int	end;
	int	*arr;
	int	save;

	x = 0;
	arr = ft_arrange(av);
	save = ps.contare - 1;
	start = 0;
	end = 15;
	if (end > save)
	{
		end = save;
	}
	while (ps.contare)
	{
		if ((stack_s.stacka[0] >= arr[start] && stack_s.stacka[0] <= arr[end]) && ps.contare)
		{	
			push_a();
			if (end < save)
			{
				start++;
				end++;
			}
			ps.contare--;
		}
		if ((stack_s.stacka[0] < arr[start]) && ps.contare)
		{
			push_a();
			ft_rev_b_shift_up();
			f_print("rb\n");
			ps.contare--;
			if (end < save)
			{
				start++;
				end++;
			}
		}
		if (stack_s.stacka[0] > arr[end])
		{
			ft_rev_a_shift_up();
			f_print("ra");

		}
	}
	printf("\n");
}
