/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:39:43 by rouali            #+#    #+#             */
/*   Updated: 2023/03/11 13:40:28 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(char **av)
{
	ft_swap_a_first(av);
	ft_swap_b_first(av);
}

void	ft_swap_b_first(char **av)
{
	int		swap;

	swap = stack_s.stackb[0];
	stack_s.stackb[0] = stack_s.stackb[1];
	stack_s.stackb[1] = swap;
	ps.contare = ft_contare(av);
}

void	ft_rev_b_shift_up(char **av)
{
	di.x = 0;
	ps.contare = ft_contare(av);
	ps.fill = ps.contare - 1;
	while (di.x <= ps.fill)
	{
		if (di.x == 0)
			ps.c = stack_s.stackb[di.x];
		else if (di.x + 1 == ps.fill + 1)
			stack_s.stackb[di.x++] = ps.c;
		if (di.x + 1 != ps.fill + 1)
			stack_s.stackb[di.x] = stack_s.stackb[di.x + 1];
		di.x++;
	}
}

void	ft_rev_b_shift_down(char **av)
{
	ps.contare = ft_contare(av);
	ps.fill = ps.contare - 1;
	while (di.x <= ps.fill)
	{
		if (ps.fill == ps.contare - 1)
		{
			ps.c = stack_s.stackb[di.x];
			stack_s.stackb[di.x++] = stack_s.stackb[ps.fill];
			stack_s.stackb[ps.fill] = ps.c;
		}
		else if (ps.fill - 1 == di.x - 1)
			stack_s.stackb[ps.fill--] = ps.c;
		if (ps.fill - 1 >= 1)
			stack_s.stackb[ps.fill] = stack_s.stackb[ps.fill - 1];
		ps.fill--;
	}
}

void	push_b(int nbr, int *str)
{
	int	x;
	int	*nbrs;

	x = 1;
	nbrs = malloc(ps.contare + 1 * sizeof(int));
	nbrs[0] = nbr;
	stack_s.stackb = &stack_s.stackb[nbr];
	while (x < ps.contare + 1)
	{
		nbrs[x] = str[x - 1];
		x++;
	}
	printf("PUSH SWAP | pb\n");
	di.x = 0;
	while (di.x < ps.contare + 1)
	{
		printf("%2d  %d\n", nbrs[di.x], stack_s.stackb[di.x]);
		di.x++;
	}
	write(1, " _  _\n", 6);
	write(1, " a  b\n", 6);
}
