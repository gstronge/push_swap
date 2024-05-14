/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:39:23 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/14 11:48:18 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_command_errors(char *command, t_list *a, t_list *b)
{
	if (command[0] == 's' && command[4] == '\0')
	{
		if ((command[1] == 'a' || command[1] == 'b' || command[1] == 's')
			&& command[2] == '\n' && command[3] == '\0')
			return ;
	}
	if (command[0] == 'p' && command[4] == '\0')
	{
		if ((command[1] == 'a' || command[1] == 'b') && command[2] == '\n'
			&& command[3] == '\0')
			return ;
	}
	if (command[0] == 'r' && command[4] == '\0')
	{
		if ((command[1] == 'a' || command[1] == 'b' || command[1] == 'r')
			&& command[2] == '\n' && command[3] == '\0')
			return ;
		else if (command[1] == 'r' && (command[2] == 'r' || command[2] == 'a'
				|| command[2] == 'b') && command[3] == '\n')
			return ;
	}
	ft_free_stack(b);
	ft_print_error(a);
}

void	ft_exucute_doubles(char *command, t_list **a, t_list **b)
{
	if (command[0] == 's' && command[1] == 's')
	{
		*a = ft_swap_b(*a);
		*b = ft_rotate_b(*b);
	}
	else if (command[0] == 'r' && command[1] == 'r' && command[2] == 'r')
	{
		*a = ft_rev_rotate_b(*a);
		*b = ft_rev_rotate_b(*b);
	}
	else if (command[0] == 'r' && command[1] == 'r')
	{
		*a = ft_rotate_b(*a);
		*b = ft_swap_b(*b);
	}
}

void	ft_execute_command(char *command, t_list **a, t_list **b)
{
	ft_command_errors(command, *a, *b);
	if (command[0] == 's' && command[1] == 'a')
		*a = ft_swap_b(*a);
	else if (command[0] == 's' && command[1] == 'b')
		*b = ft_swap_b(*b);
	else if (command[0] == 'r' && command[1] == 'a')
		*a = ft_rotate_b(*a);
	else if (command[0] == 'r' && command[1] == 'b')
		*b = ft_rotate_b(*b);
	else if (command[0] == 'r' && command[1] == 'r' && command[2] == 'a')
		*a = ft_rev_rotate_b(*a);
	else if (command[0] == 'r' && command[1] == 'r' && command[2] == 'b')
		*b = ft_rev_rotate_b(*b);
	else if (command[0] == 'p' && command[1] == 'a')
		*a = ft_push_to_b(b, a);
	else if (command[0] == 'p' && command[1] == 'b')
		*b = ft_push_to_b(a, b);
	else
		ft_exucute_doubles(command, a, b);
}

void	ft_result(t_list *a, t_list *b)
{
	if (b == NULL && ft_check_order(a, 'a'))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*command;

	a = NULL;
	b = NULL;
	command = NULL;
	if (argc > 1)
	{
		ft_errors(argc, argv, a);
		ft_make_stack(&a, 0, argc, argv);
		while (1)
		{
			command = get_next_line(0);
			if (command == NULL)
				break ;
			ft_execute_command(command, &a, &b);
			if (command != NULL)
				free(command);
		}
		ft_result(a, b);
	}
	ft_free_stack(a);
	ft_free_stack(b);
}
