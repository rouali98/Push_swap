/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:14 by rouali            #+#    #+#             */
/*   Updated: 2023/03/10 20:38:51 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char *str, char c)
{
	int		x;
	int		y;
	int		save;
	char	**arg;

	x = 0;
	y = 0;
	if (!str)
		return (0);
	arg = malloc(sizeof(char *) * (ft_word(str, c) + 1));
	if (!arg)
		return (0);
	while (x < ft_word(str, c) && str[y])
	{
		while (str[y] == c)
			y++;
		save = y;
		while (str[y] != c && str[y])
			y++;
		arg[x] = ft_strndup(&str[save], y - save);
		if (arg[x++] == 0)
			return (NULL);
	}
	arg[x] = 0;
	return (arg);
}

int	*ft_arg(char **str)
{
	int		x;
	int		y;
	int		z;
	int		*arg;

	x = 1;
	y = 0;
	z = 0;
	arg = malloc(sizeof(int *) * 100);
	if (!arg)
		exit(1);
	while (str[x])
	{
		while (ft_split(str[x], ' ')[y])
			arg[z++] = ft_atoi(ft_split(str[x], ' ')[y++]);
		y = 0;
		x++;
	}
	return (arg);
}

int	ft_contare(char **av)
{
	int	x;
	int	y;
	int	c;

	x = 1;
	c = 0;
	while (av[x])
	{
		y = 0;
		while (ft_split(av[x], ' ')[y++])
		{
			c++;
		}
		x++;
	}
	return (c);
}

void	ft_write(char **arg)
{
	//ft_swap_first(arg);
	ft_rev_shift_up(arg);
	//ft_rev_shift_down(arg);
	//ss(ps.contare);
	//stack_s.stackb = push_a(stack_s.stacka[0], stack_s.stackb, ps.contare);
	//printf("PUSH SWAP | pa\n");
	//di.x = 0;
	//while (di.x < ps.contare + 1)
	//{
	//	printf("%2d  %d\n", stack_s.stacka[di.x], stack_s.stackb[di.x]);
	//	di.x++;
	//}
	//write(1, " _  _\n", 6);
	//write(1, " a  b\n", 6);
	//stack_s.stacka = push_b(stack_s.stackb[0], stack_s.stacka, ps.contare + 1);
	//printf("PUSH SWAP | pb\n");
	//di.x = 0;
	//while (di.x < ps.contare + 1)
	//{
	//	printf("%2d  %d\n", stack_s.stacka[di.x], stack_s.stackb[di.x]);
	//	di.x++;
	//}
	//write(1, " _  _\n", 6);
	//write(1, " a  b\n", 6);
}

int	main(int ac, char **av)
{
	if (ac <= 0)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	stack_s.stacka = ft_arg(av);
	ps.contare = ft_contare(av);
	stack_s.stackb = malloc(sizeof(int) * ps.contare + 1);
	if (!stack_s.stackb)
		return (0);
	ft_write(av);
	return (0);
}
