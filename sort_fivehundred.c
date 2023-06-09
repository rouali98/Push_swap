/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fivehundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:58:20 by rouali            #+#    #+#             */
/*   Updated: 2023/04/14 16:21:20 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_fivehundred(char **av)
{
	int	*arr;
	int	save;

	arr = ft_arrange(av);
	save = ps.contare - 1;
	di.start = 0;
	di.end = 35;
	if (di.end > save)
		di.end = save;
	while (ps.contare)
	{
		ft_range(arr, save);
	}
	while (ps.sb)
	{
		ft_return_sb();
	}
	free(arr);
}
