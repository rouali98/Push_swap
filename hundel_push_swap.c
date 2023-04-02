// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   hundel_push_swap.c                                 :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/04/02 22:12:53 by rouali            #+#    #+#             */
// /*   Updated: 2023/04/02 22:22:56 by rouali           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void space_valid(char **av)
// {
// 	int	c;

// 	c = 0;
// 	while (av[c])
// 	{
// 		if ((av[c][0] == ' ' && av[c][1] == '\0')|| av[c][0] == '\0')
// 		{
// 			write(1, "Error\n", 6);
// 			exit(1);
// 		}
// 		c++;
// 	}
// }

// void	ft_check_is_not_nbr(char **av)
// {
//     char	**arg;

//     arg = args_with_no_space(av);
// 	di.x = 1;
// 	while (arg[di.x])
// 	{
// 		di.y = 0;
// 		while (arg[di.x][di.y])
// 		{
// 			if ((arg[di.x][di.y] >= '0' && arg[di.x][di.y] <= '9') \
// 			|| (arg[di.x][di.y] == '-') || (arg[di.x][di.y] == '+'))
// 			{
// 				if (arg[di.x][di.y] == '-' || arg[di.x][di.y] == '+')
// 				{
// 					if (di.y != 0)
// 					{
// 						write(1, "Error\n", 6);
// 						exit(1);
// 					}
// 				}
// 				di.y++;
// 			}
// 			else
// 			{
// 				write(1, "Errorr\n", 6);
// 				exit(1);
// 			}
// 		}
//         di.x++;
// 	}
// }
