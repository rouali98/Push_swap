/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:47:05 by rouali            #+#    #+#             */
/*   Updated: 2023/04/01 10:51:06 by rouali           ###   ########.fr       */
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

long	ft_atoi(char *str)
{
	int		x;
	int		y;
	long	result;

	x = 0;
	y = 1;
	result = 0;
	while (str[x] == 32 || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			y = y * -1;
		x++;
	}
	while (ft_isdigit((int)str[x]))
	{
		result = result * 10 + str[x] - '0';
		x++;
	}
	return (result * y);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int	ft_word(char *s, char c)
{
	int	x;

	x = 0;
	ps.contare = 0;
	while (s[x])
	{
		if ((x == 0 && s[x] != c) || (s[x] == c && s[x + 1] && s[x + 1] != c))
		{
			ps.contare++;
		}
		x++;
	}
	return (ps.contare);
}
