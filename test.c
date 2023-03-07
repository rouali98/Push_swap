#include <stdio.h>
#include <stdlib.h>

int	ft_word(char *str, char c)
{
	int x;
	int count;

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

char	*ft_strdup(char *str, int n)
{
	int x;
	char *dest;

	x = 0;
	dest = (char *)malloc(sizeof(char) * (n + 1));
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

char	**ft_split(char *str, char c)
{
	int		x;
	int		y;
	int		save;
	char	**strl;

	x = 0;
	y = 0;
	if (!str)
		return (0);
	strl = (char **)malloc(sizeof(char *) * (ft_word(str, c) + 1));
	if (!strl)
		return (0);
	while (x < ft_word(str, c) && str[y])
	{
		while (str[y] == c)
			y++;
		save = y;
		while (str[y] != c && str[y])
			y++;
		strl[x] = ft_strdup(&str[save], y - save);
		if (strl[x++] == 0)
			return (NULL);
	}
	strl[x] = 0;
	return (strl);
}

int	main(int ac, char **av)
{
	int		x;
	int		y;
	int		z;
	char	**arg;

	x = 1;
	y = 0;
	z = 0;
	arg = malloc(sizeof(char *) * 500);
	while (av[x])
	{
		while (ft_split(av[x], ' ')[y])
		{
			arg[z++] = ft_split(av[x], ' ')[y];
			y++;
		}
		y = 0;
		x++;
	}
	x = 0;
	while (arg[x])
	{
		printf("%s\n", arg[x]);
		x++;
	}
	return (0);
}