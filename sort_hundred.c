/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:22:31 by rouali            #+#    #+#             */
/*   Updated: 2023/03/31 23:57:18 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mx(void)
{
	int	max;

	di.x = 0;
	max = stack_s.stackb[0];
	while (di.x < ps.sb)
	{
		if (stack_s.stackb[di.x] > max)
			max = stack_s.stackb[di.x];
		di.x++;
	}
	return (max);
}

int	*ft_arrange(char **av)
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

void	ft_confined(int *arr, int save)
{
	if ((stack_s.stacka[0] >= arr[di.start] \
	&& stack_s.stacka[0] <= arr[di.end]) && ps.contare)
	{	
		push_a();
		if (di.end < save)
		{
			di.start++;
			di.end++;
		}
		ps.contare--;
	}
}

void	ft_smaller(int *arr, int save)
{
	if ((stack_s.stacka[0] < arr[di.start]) && ps.contare)
	{
		push_a();
		ft_rev_b_shift_up();
		f_print("rb");
		ps.contare--;
		if (di.end < save)
		{
			di.start++;
			di.end++;
		}
	}
}

void	ft_larger(int *arr)
{
	if (stack_s.stacka[0] > arr[di.end])
	{
		ft_rev_a_shift_up();
		f_print("ra");
	}
}

void	ft_range(int *arr, int save)
{
	ft_confined(arr, save);
	ft_smaller(arr, save);
	ft_larger(arr);
}

int	ft_max(void)
{
	int	max;

	int x = 0;
	max = 0;
	while (x < ps.sb)
	{
		if (stack_s.stackb[x] == ft_mx())
		{
			max = x;
			return (max);
		}
		x++;
	}
	return (max);
}

void	ft_sort_hundred(char **av)
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
	di.end = 15;
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
