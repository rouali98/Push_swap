/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:11:24 by rouali            #+#    #+#             */
/*   Updated: 2023/03/04 19:23:44 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t ft_f_word(char const *s, char c)
{
	size_t i;
	size_t lsize;

	i = 0;
	lsize = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] && s[i + 1] != c))
		{
			lsize++;
		}
		i++;
	}
	return (lsize);
}

char *ft_strndup(const char *s1, size_t n)
{
	size_t i;
	char *dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	while (i < n)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char **ft_split(char const *s, char c)
{
	size_t i;
	size_t j;
	size_t save;
	char **strl;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	strl = (char **)malloc(sizeof(char *) * (ft_f_word(s, c) + 1));
	if (!strl)
		return (0);
	while (i < ft_f_word(s, c) && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		save = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		strl[i] = ft_strndup(&s[save], j - save);
		if (strl[i++] == 0)
			return (NULL);
	}
	strl[i] = 0;
	return (strl);
}

int main(int c, char *av[])
{
	int i;
	int j;
	char **arg;

	arg = malloc(500 * sizeof(char *));
	int id = 1;
	int b = 0;
	int a = 0;
	while (av[id])
	{
		while (ft_split(av[id], ' ')[b])
		{
			arg[a++] = ft_split(av[id], ' ')[b];
			b++;
		}
		b = 0;
		id++;
	}
	i = 0;
	while (arg[i])
	{
		printf("%s\n", arg[i]);
		i++;
	}
	return (0);
}
