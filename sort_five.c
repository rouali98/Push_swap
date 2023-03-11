/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:08:59 by rouali            #+#    #+#             */
/*   Updated: 2023/03/11 20:01:13 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(char **av)
{
	int *max;
	int z;

	av = 0;
	di.x = 0;
	max = malloc(sizeof(int *) * ps.contare + 1);
	z = 0;
	while (stack_s.stacka[di.x] < stack_s.stacka[di.x + 1])
	{
		max[z++] = stack_s.stacka[di.x++];
		printf("max = %d\n", max[z]);
		printf("max = %d\n", stack_s.stacka[di.x]);
		printf("max = %d\n", stack_s.stacka[di.x + 1]);
	}
	//if (stack_s.stacka[0] < stack_s.stacka[1])
	//{

	//}
}
