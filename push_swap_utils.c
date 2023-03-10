/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:47:05 by rouali            #+#    #+#             */
/*   Updated: 2023/03/10 12:25:02 by rouali           ###   ########.fr       */
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

//int	ft_word(char *str, char c)
//{
//	int	x;
//	int	contare;

//	x = 0;
//	contare = 0;
//	while (str[x])
//	{
//		if ((x == 0 && str[x] != contare) || (str[x] == \
//		contare && str[x + 1] && str[x + 1] != contare))
//			contare++;
//		x++;
//	}
//	return (contare);
//}

int	ft_word(char *s, char c)
{
	int	x;
	int	contare;

	x = 0;
	contare = 0;
	while (s[x])
	{
		if ((x == 0 && s[x] != c) || (s[x] == c && s[x + 1] && s[x + 1] != c))
		{
			contare++;
		}
		x++;
	}
	return (contare);
}
