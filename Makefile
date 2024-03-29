# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rouali <rouali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 12:08:31 by rouali            #+#    #+#              #
#    Updated: 2023/04/13 20:01:21 by rouali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c \
		push_swap_utils.c \
		stacka.c \
		stackb.c \
		sort_three.c \
		sort_five.c \
		sort_hundred.c \
		sort_hundred_utils.c \
		sort_fivehundred.c \
		hundel_push_swap.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

