/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:14 by rouali            #+#    #+#             */
/*   Updated: 2023/03/09 20:34:04 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = j * -1;
		i++;
	}
	while (ft_isdigit((int)str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * j);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_word(char *str, char c)
{
	int	x;
	int	contare;

	x = 0;
	contare = 0;
	while (str[x])
	{
		if ((x == 0 && str[x] != contare) || (str[x] == contare && str[x + 1] && str[x + 1] != contare))
			contare++;
		x++;
	}
	return (contare);
}

char	*ft_strndup(char *str, int n)
{
	int		x;
	char	*dest;

	x = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	while (x < n)
	{
		dest[x] = str[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}
int a;

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
	a = x + 1;
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
	int x;
	int y;
	int c;

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

void	ft_swap_first(char **av)
{
	int		*stacka;
	int		*stackb;
	int		swap;
	int		x;
	int		contare;

	x = 0;
	stacka = ft_arg(av);
	swap = stacka[0];
	stacka[0] = stacka[1];
	stacka[1] = swap;
	contare = ft_contare(av);
	write(1, "PUSH SWAP | sa :\n", 17);
	while (x < contare)
	{
		printf("%2d\n", stacka[x]);
		x++;
	}
	while (x < contare)
	{
		printf("%d\n", stackb[x]);
		x++;
	}
	write(1, " _  _\n", 6);
	write(1, " a  b\n", 6);
}

void	ft_rev_shift_up(char **av)
{
	int		*stacka;
	int		*stackb;
	int		contare;
	int		x;
	int		c;
	int		s;

	x = 0;
	stacka = ft_arg(av);
	contare = ft_contare(av);
	s = contare - 1;
	while (x <= s)
	{
		if (!x)
		{
			c = stacka[s];
			stacka[s] = stacka[0];
		}
		else if (x + 1 == s)
			stacka[x++] = c;
		if (x + 1 != s + 1)
			stacka[x] = stacka[x + 1];
		x++;
	}
	write(1, "PUSH SWAP | ra :\n", 17);
	x = 0;
	while (x < contare)
	{
		printf("%2d\n", stacka[x]);
		x++;
	}
	while (x < contare)
	{
		printf("%d\n", stackb[x]);
		x++;
	}
	write(1, " _  _\n", 6);
	write(1, " a  b\n", 6);
}

void	ft_rev_shift_down(char **av)
{
	int		*stacka;
	int		*stackb;
	int		contare;
	int		x;
	int		c;
	int		s;

	x = 0;
	stacka = ft_arg(av);
	contare = ft_contare(av);
	s = contare - 1;
	while (x <= s)
	{
		if (s == contare - 1)
		{
			c = stacka[x];
			stacka[x] = stacka[s];
			x++;
		}
		else if (s - 1 == x - 1)
			stacka[s--] = c;
		if (s - 1 >= 1)
			stacka[s] = stacka[s - 1];
		s--;
	}
	write(1, "PUSH SWAP | rra :\n", 18);
	x = 0;
	while (x < contare)
	{
		printf("%d\n", stacka[x]);
		x++;
	}
	while (x < contare)
	{
		printf("%d\n", stackb[x]);
		x++;
	}
	write(1, " _  _\n", 6);
	write(1, " a  b\n", 6);
}

//int *push_a(int nbr, int *str, int contare)
//{
//	int a[contare];
//	int b;
//	int x;
//	int first;
//	int *nbrs = malloc(contare * sizeof(int));

//	x = 1;
//	nbrs[0] = nbr;
//	stack_s.stacka = &stack_s.stacka[1];
//	while (x < contare)
//	{
//		nbrs[x] = str[x - 1];
//		x++;
//	}
//	write(1, "pa\n", 3);
//	return (nbrs);
//}

int *push_b(int nbr, int *str, int contare)
{
	int a[contare];
	int b;
	int x;
	int first;
	int *nbrs = malloc(contare * sizeof(int));

	x = 1;
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

void ss(int contare)
{
	stack_s.stackb = push_a(stack_s.stacka[0], stack_s.stackb, contare);
	stack_s.stacka = push_b(stack_s.stackb[0], stack_s.stacka, contare + 1);
}

int	main(int ac, char **av)
{
	int		contare;
	int		x;

	stack_s.stacka = ft_arg(av);
	contare = ft_contare(av);
	stack_s.stackb = malloc(sizeof(int) * contare + 1);
	if (!stack_s.stackb)
		return (0);
	stack_s.stackb[0] = 500;
	//ft_swap_first(av);
	//ft_rev_shift_up(av);
	//ft_rev_shift_down(av);
	//ss(contare);
	stack_s.stackb = push_a(stack_s.stacka[0], stack_s.stackb, contare);
	printf("PUSH SWAP | pa\n");
	x = 0;
	while (x < contare + 1)
	{
		printf("%2d  %d\n", stack_s.stacka[x], stack_s.stackb[x]);
		x++;
	}
	write(1, " _  _\n", 6);
	write(1, " a  b\n", 6);
	//stack_s.stacka = push_b(stack_s.stackb[0], stack_s.stacka, contare + 1);
	//printf("PUSH SWAP | pb\n");
	//x = 0;
	//while (x < contare + 1)
	//{
	//	printf("%2d  %d\n", stack_s.stacka[x], stack_s.stackb[x]);
	//	x++;
	//}
	//write(1, " _  _\n", 6);
	//write(1, " a  b\n", 6);
	return (0);
}
