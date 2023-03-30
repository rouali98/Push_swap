/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:22:31 by rouali            #+#    #+#             */
/*   Updated: 2023/03/30 18:16:12 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		f_print("rb\n");
		ps.contare--;
		if (di.end < save)
		{
			di.start++;
			di.end++;
		}
	}
}

void	ft_range(int *arr, int save)
{
	ft_confined(arr, save);
	ft_smaller(arr, save);
	ft_larger(arr);
}

void	ft_larger(int *arr)
{
	if (stack_s.stacka[0] > arr[di.end])
	{
		ft_rev_a_shift_up();
		f_print("ra");
	}
}

void	ft_sort_hundred(char **av)
{
	int	x;
	int	*arr;
	int	save;

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
	printf("arr = %d\n", arr[1]);
	printf("\n");
}
