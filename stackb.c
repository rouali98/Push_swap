/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:39:43 by rouali            #+#    #+#             */
/*   Updated: 2023/04/02 16:31:18 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(void)
{
	ft_swap_a_first();
	ft_swap_b_first();
}

/* SB */

void	ft_swap_b_first(void)
{
	int		swap;

	swap = stack_s.stackb[0];
	stack_s.stackb[0] = stack_s.stackb[1];
	stack_s.stackb[1] = swap;
	write(1, "sb\n", 3);
}

/* RB */

void	ft_rev_b_shift_up(void)
{
	di.x = 0;
	ps.fill = ps.sb - 1;
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
	write(1, "rb\n", 3);
}

/* RRB */

void	ft_rev_b_shift_down(void)
{
	di.x = 0;
	ps.fill = ps.sb - 1;
	while (di.x <= ps.fill)
	{
		if (ps.fill == ps.sb - 1)
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
	stack_s.stackb = stack_s.stackb;
	write(1, "rrb\n", 4);
}

/* PB */

void	push_b(void)
{
	int	*nbrs;

	nbrs = malloc((ps.contare + 1) * sizeof(int));
	nbrs[0] = stack_s.stackb[0];
	di.y = 0;
	di.x = 1;
	stack_s.stackb = &stack_s.stackb[1];
	while (di.y < ps.contare)
	{
		nbrs[di.x] = stack_s.stacka[di.y];
		di.x++;
		di.y++;
	}
	stack_s.stacka = nbrs;
	ps.sb--;
	write(1, "pa\n", 3);
}
