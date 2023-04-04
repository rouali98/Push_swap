/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacka.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:39:21 by rouali            #+#    #+#             */
/*   Updated: 2023/04/03 16:34:24 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_write_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

/* SA */

void	ft_swap_a_first(void)
{
	int		swap;

	swap = stack_s.stacka[0];
	stack_s.stacka[0] = stack_s.stacka[1];
	stack_s.stacka[1] = swap;
	write(1, "sa\n", 3);
}

/* RA */

void	ft_rev_a_shift_up(void)
{
	di.x = 0;
	ps.fill = ps.contare - 1;
	while (di.x <= ps.fill)
	{
		if (di.x == 0)
			ps.c = stack_s.stacka[di.x];
		else if (di.x + 1 == ps.fill + 1)
			stack_s.stacka[di.x++] = ps.c;
		if (di.x + 1 != ps.fill + 1)
			stack_s.stacka[di.x] = stack_s.stacka[di.x + 1];
		di.x++;
	}
	write(1, "ra\n", 3);
}

/* RRA */

void	ft_rev_a_shift_down(void)
{
	di.x = 0;
	ps.fill = ps.contare - 1;
	while (di.x <= ps.fill)
	{
		if (ps.fill == ps.contare - 1)
		{
			ps.c = stack_s.stacka[di.x];
			stack_s.stacka[di.x++] = stack_s.stacka[ps.fill];
			stack_s.stacka[ps.fill] = ps.c;
		}
		else if (ps.fill - 1 == di.x - 1)
			stack_s.stacka[ps.fill--] = ps.c;
		if (ps.fill - 1 >= 1)
			stack_s.stacka[ps.fill] = stack_s.stacka[ps.fill - 1];
		ps.fill--;
	}
	stack_s.stacka = stack_s.stacka;
	write(1, "rra\n", 4);
}

/* PA */

void	push_a(void)
{
	int	*nbrs;

	di.x = 1;
	nbrs = malloc((ps.sb + 1) * sizeof(int));
	nbrs[0] = stack_s.stacka[0];
	di.y = 0;
	stack_s.stacka = &stack_s.stacka[1];
	while (di.y < ps.sb)
	{
		nbrs[di.x] = stack_s.stackb[di.y];
		di.x++;
		di.y++;
	}
	ps.sb++;
	stack_s.stackb = nbrs;
	write(1, "pb\n", 3);
}
