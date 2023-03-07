/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:14 by rouali            #+#    #+#             */
/*   Updated: 2023/03/07 19:23:44 by rouali           ###   ########.fr       */
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
	int	count;

	x = 0;
	count = 0;
	while (str[x])
	{
		if ((x == 0 && str[x] != c) || (str[x] == c && str[x + 1] && str[x + 1] != c))
			count++;
		x++;
	}
	return (count);
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

int	ft_count(char **av)
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
	int		count;
	int		x;
	int		c;

	x = 0;
	stacka = ft_arg(av);
	c = stacka[0];
	stacka[0] = stacka[1];
	stacka[1] = c;
	count = ft_count(av);
	printf("PUSH SWAP | sa :\n");
	while (x < count)
	{
		printf("%d\n", stacka[x]);
		x++;
	}
	while (x < count)
	{
		printf("%d\n", stackb[x]);
		x++;
	}
	printf("_ _\n");
	printf("a b\n");
}


void	ft_rev_shift_up(char **av)
{
	int		*stacka;
	int		*stackb;
	int		count;
	int		x;
	int		c;
	int		s;

	x = 0;
	stacka = ft_arg(av);
	count = ft_count(av);
	s = count - 1;
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
	printf("PUSH SWAP | ra :\n");
	x = 0;
	while (x < count)
	{
		printf("%d\n", stacka[x]);
		x++;
	}
	while (x < count)
	{
		printf("%d\n", stackb[x]);
		x++;
	}
	printf("_ _\n");
	printf("a b\n");
}

void	ft_rev_shift_down(char **av)
{
	int		*stacka;
	int		*stackb;
	int		count;
	int		x;
	int		c;
	int		s;

	x = 0;
	stacka = ft_arg(av);
	count = ft_count(av);
	s = count - 1;
	while (x <= s)
	{
		if (s == count - 1)
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
	printf("PUSH SWAP | rra :\n");
	x = 0;
	while (x < count)
	{
		printf("%d\n", stacka[x]);
		x++;
	}
	while (x < count)
	{
		printf("%d\n", stackb[x]);
		x++;
	}
	printf("_ _\n");
	printf("a b\n");
}

int	main(int ac, char **av)
{
	int		*stacka;
	int		*stackb;
	int		count;
	int		x;

	stacka = ft_arg(av);
	count = ft_count(av);
	stackb = malloc(sizeof(int *) * ft_count(av));
	x = stacka[0];
	printf("x = %d\n", x);
	printf("stacka = %d\n", stacka[0]);
	printf("stackb = %d\n", stackb[0]);
	//printf("PUSH SWAP | pa :\n");
	//x = 0;
	//while (x < count)
	//	printf("%d\n", stacka[x++]);
	//x = 0;
	//while (x < count)
	//	printf("%d\n", stackb[x++]);
	printf("_ _\n");
	printf("a b\n");
	ft_swap_first(av);
	ft_rev_shift_up(av);
	ft_rev_shift_down(av);
	return (0);
}
