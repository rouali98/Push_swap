/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:39:43 by rouali            #+#    #+#             */
/*   Updated: 2023/03/10 11:55:11 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*push_b(int nbr, int *str, int contare)
{
	int	x;
	int	*nbrs;

	x = 1;
	nbrs = malloc(contare * sizeof(int));
	nbrs[0] = nbr;
	stack_s.stackb = &stack_s.stackb[1];
	while (x < contare)
	{
		nbrs[x] = str[x - 1];
		x++;
	}
	write(1, "pb\n", 3);
	return (nbrs);
}
