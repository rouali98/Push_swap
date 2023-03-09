/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacka.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:39:21 by rouali            #+#    #+#             */
/*   Updated: 2023/03/09 18:04:07 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//void	ft_swap_first(char **av)
//{
//	int		swap;

//	di.x = 0;
//	stack_s.stacka = ft_arg(av);
//	swap = stack_s.stacka[0];
//	stack_s.stacka[0] = stack_s.stacka[1];
//	stack_s.stacka[1] = swap;
//	ps.contare = ft_contare(av);
//	write(1, "PUSH SWAP | sa :\n", 17);
//	while (di.x < ps.contare)
//		printf("%2d\n", stack_s.stacka[di.x++]);
//	while (di.x < ps.contare)
//		printf("%d\n", stack_s.stackb[di.x++]);
//	write(1, " _  _\n", 6);
//	write(1, " a  b\n", 6);
//}

//void	ft_rev_shift_up(char **av)
//{
//	di.x = 0;
//	stack_s.stacka = ft_arg(av);
//	ps.contare = ft_contare(av);
//	ps.fill = ps.contare - 1;
//	while (di.x <= ps.fill)
//	{
//		if (!di.x)
//		{
//			ps.c = stack_s.stacka[ps.fill];
//			stack_s.stacka[ps.fill] = stack_s.stacka[0];
//		}
//		else if (di.x + 1 == ps.fill)
//			stack_s.stacka[di.x++] = ps.c;
//		if (di.x + 1 != ps.fill + 1)
//			stack_s.stacka[di.x] = stack_s.stacka[di.x + 1];
//		di.x++;
//	}
//	write(1, "PUSH SWAP | ra :\n", 17);
//	di.x = 0;
//	while (di.x < ps.contare)
//		printf("%2d\n", stack_s.stacka[di.x++]);
//	while (di.x < ps.contare)
//		printf("%d\n", stack_s.stackb[di.x++]);
//	write(1, " _  _\n", 6);
//	write(1, " a  b\n", 6);
//}

//void	ft_rev_shift_down(char **av)
//{
//	di.x = 0;
//	stack_s.stacka = ft_arg(av);
//	ps.contare = ft_contare(av);
//	ps.fill = ps.contare - 1;
//	while (di.x <= ps.fill)
//	{
//		if (ps.fill == ps.contare - 1)
//		{
//			ps.c = stack_s.stacka[di.x++];
//			stack_s.stacka[di.x++] = stack_s.stacka[ps.fill];
//		}
//		else if (ps.fill - 1 == di.x - 1)
//			stack_s.stacka[ps.fill--] = ps.c;
//		if (ps.fill - 1 >= 1)
//			stack_s.stacka[ps.fill] = stack_s.stacka[ps.fill - 1];
//		ps.fill--;
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

int	*push_a(int nbr, int *str, int contare)
{
	int	b;
	int	*nbrs;

	di.x = 1;
	nbrs = malloc(contare * sizeof(int));
	nbrs[0] = nbr;
	stack_s.stacka = &stack_s.stacka[1];
	while (di.x < contare)
	{
		nbrs[di.x] = str[di.x - 1];
		di.x++;
	}
	write(1, "pa\n", 3);
	return (nbrs);
}
