/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:28:49 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/07 15:01:19 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_list *list)
{
	t_list	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	ft_print_error(t_list *a)
{
	ft_free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_print_error_split(t_list *a, char **strstr)
{
	ft_free_array(strstr);
	ft_free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_check_duplicates(t_list *a)
{
	t_list	*new_head;
	t_list	*current;

	new_head = a;
	current = a;
	while (new_head)
	{
		current = new_head->next;
		while (current)
		{
			if (new_head->data == current->data)
				ft_print_error(a);
			current = current->next;
		}
		new_head = new_head->next;
	}
}

void	ft_errors(int argc, char **strstr, t_list *a)
{
	int	i;

	i = 1;
	if (strstr[1][0] == '\0')
		exit(EXIT_SUCCESS);
	if (argc < 2 || strstr == NULL)
		ft_print_error(a);
	while (strstr[i] != NULL && strstr[i][0] != '\0')
	{
		if ((strstr[i][0] > '9' || strstr[i][0] < '0') && strstr[i][0] != ' '
			&& strstr[i][0] != '\t' && strstr[i][0] != '-'
			&& strstr[i][0] != '+')
			ft_print_error(a);
		if ((strstr[i][0] == '-' || strstr[i][0] == '+') && (strstr[i][1] > '9'
				|| strstr[i][1] < '0'))
			ft_print_error(a);
		i++;
	}
}
