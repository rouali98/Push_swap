/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacka.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:39:21 by rouali            #+#    #+#             */
/*   Updated: 2023/03/17 20:19:41 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_print(char *str)
{
	printf("PUSH SWAP | %s\n", str);
	di.x = 0;
	while (di.x < ps.contare)
	{
		printf("%2d  %d\n", stack_s.stacka[di.x], stack_s.stackb[di.x]);
		di.x++;
	}
	write(1, " _  _\n", 6);
	write(1, " a  b\n", 6);
}

void	f_printp(char *str)
{
	printf("PUSH SWAP | %s\n", str);
	di.x = 0;
	while (di.x < ps.contare)
		printf("%2d\n", stack_s.stacka[di.x++]);
	while (di.x < ps.contare)
		printf("%d\n", stack_s.stackb[di.x++]);
	write(1, " _  _\n", 6);
	write(1, " a  b\n", 6);
}

/* SA */

void	ft_swap_a_first(void)
{
	int		swap;

	swap = stack_s.stacka[0];
	stack_s.stacka[0] = stack_s.stacka[1];
	stack_s.stacka[1] = swap;
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
}

//void	ft_rev_shift_down(char **av)
//{
//	di.x = 0;
//	stack_s.stacka = ft_arg(av);
//	ps.contare = ft_contare(av);
//	ps.fill = ps.contare - 1;
//	if (ps.contare == 2)
//	{
//		ps.c = stack_s.stacka[0];
//		stack_s.stacka[0] = stack_s.stacka[ps.fill];
//		stack_s.stacka[ps.fill] = ps.c;
//	}
//	else
//	{
//		while (di.x <= ps.fill)
//		{
//			if (ps.fill == ps.contare - 1)
//			{
//				ps.c = stack_s.stacka[di.x];
//				stack_s.stacka[di.x++] = stack_s.stacka[ps.fill];
//			}
//			else if (ps.fill - 1 == di.x - 1)
//				stack_s.stacka[ps.fill--] = ps.c;
//			if (ps.fill - 1 >= 1)
//				stack_s.stacka[ps.fill] = stack_s.stacka[ps.fill - 1];
//			ps.fill--;
//		}
//	}
//	write(1, "PUSH SWAP | rra :\n", 18);
//	di.x = 0;
//	while (di.x < ps.contare)
//		printf("%2d\n", stack_s.stacka[di.x++]);
//	while (di.x < ps.contare)
//		printf("%d\n", stack_s.stackb[di.x++]);
//	write(1, " _  _\n", 6);
//	write(1, " a  b\n", 6);
//}

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
}

/* PA */

void	push_a(int *str)
{
	int	*nbrs;

	di.x = 1;
	nbrs = malloc(100 * sizeof(int));
	nbrs[0] = stack_s.stacka[0];
	int b = 0;
	stack_s.stacka = &stack_s.stacka[1];
	while (di.x < ps.contare - 1)
	{
		nbrs[di.x] = str[b++];
		di.x++;
	}
	printf("PUSH SWAP | pa\n");
	di.x = 0;
	while (di.x < ps.contare - 1)
	{
		printf("%2d  %d\n", stack_s.stacka[di.x], nbrs[di.x]);
		di.x++;
	}
	write(1, " _  _\n", 6);
	write(1, " a  b\n", 6);
}
