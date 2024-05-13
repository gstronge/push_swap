# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 13:11:37 by gstronge          #+#    #+#              #
#    Updated: 2024/05/13 16:54:06 by gstronge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
NAME	= push_swap
SRCS	= atoi.c errors.c make_index.c make_stack.c operations.c order_stack.c \
rotations.c six_nodes.c split.c
OBJS	= $(SRCS:.c=.o)
SRCS_M	= push_swap.c
OBJS_M	= $(SRCS_M:.c=.o)
HEAD	= push_swap.h
NAME_B	= checker
SRCS_B	= operations_bonus.c push_swap_bonus.c
OBJS_B	= $(SRCS_B:.c=.o)
HEAD_B	= push_swap_bonus.h
CFLAGS	= -Wall -Werror -Wextra
LIBS_DIR= libft
LIBFT	= $(LIBS_DIR)/libft.a

all:	$(NAME)

$(NAME): $(OBJS_M) $(OBJS) $(HEAD)
	$(CC) $(CFLAGS) $(OBJS_M) $(OBJS) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJS) $(OBJS_B) $(HEAD_B) $(HEAD) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS) $(OBJS_B) $(LIBFT)

$(LIBFT):
	@make -C $(LIBS_DIR)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_B)
	@rm -f $(OBJS_M)
	@make clean -C $(LIBS_DIR)

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@make fclean -C $(LIBS_DIR)

re:		fclean all

.PHONY: all clean fclean re bonus