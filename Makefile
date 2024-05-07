# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 13:11:37 by gstronge          #+#    #+#              #
#    Updated: 2024/05/07 12:57:01 by gstronge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= push_swap
SRCS	= push_swap.c split.c operations.c errors.c six_nodes.c order_stack.c \
rotations.c make_index.c atoi.c
OBJS	= $(SRCS:.c=.o)
HEAD	= push_swap.h
CFLAGS	= -Wall -Werror -Wextra

all:	$(NAME)

$(OBJS): %.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

$(NAME): $(OBJS) $(HEAD)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re