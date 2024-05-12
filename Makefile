# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 13:11:37 by gstronge          #+#    #+#              #
#    Updated: 2024/05/11 18:45:25 by gstronge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
NAME	= push_swap
SRCS	= atoi.c errors.c make_index.c make_stack.c operations.c order_stack.c \
rotations.c six_nodes.c split.c
OBJS	= $(SRCS:.c=.o)
HEAD	= push_swap.h
NAME_B	= checker
SRCS_B	= operations_bonus.c push_swap_bonus.c
OBJS_B	= $(SRCS_B:.c=.o)
HEAD_B	= push_swap_bonus.h
CFLAGS	= -Wall -Werror -Wextra
LIBS_DIR= libft
LIBFT	= $(LIB_DIR)/libft.a
LIBS	= -L$(LIBS_DIR) -lft

all:	$(NAME)

$(NAME): $(OBJS) $(HEAD)
	$(CC) $(CFLAGS) push_swap.c $(OBJS) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJS) $(OBJS_B) $(HEAD_B) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS) $(OBJS_B) $(LIBS)

$(LIBFT):
	@make -C $(LIBS_DIR)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_B)
	@make clean -C $(LIBS_DIR)

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@make fclean -C $(LIBS_DIR)

re:		fclean all

.PHONY: all clean fclean re bonus