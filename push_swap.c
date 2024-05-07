/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:57:37 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/07 15:02:28 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_a(t_list **a, int argc, char **strstr)
{
	t_list	*current;
	int		size;

	*a = (t_list *)malloc(1 * sizeof(t_list));
	if (a == NULL)
		return (0);
	size = 1;
	current = *a;
	(*a)->data = ft_atoi(&strstr[size][0], *a);
	(*a)->next = NULL;
	size++;
	while (size < argc)
	{
		ft_add_node(current, &strstr[size][0], *a);
		current = current->next;
		size++;
	}
	ft_check_duplicates(*a);
	size = ft_add_index(a, argc);
	return (size);
}

int	ft_create_a_split(t_list **a, int argc, char **strstr)
{
	t_list	*current;
	int		size;

	*a = (t_list *)malloc(1 * sizeof(t_list));
	if (a == NULL)
		return (0);
	size = 1;
	current = *a;
	(*a)->data = ft_atoi_split(&strstr[size][0], *a, strstr);
	(*a)->next = NULL;
	size++;
	while (size < argc)
	{
		ft_add_node_split(current, &strstr[size][0], *a, strstr);
		current = current->next;
		size++;
	}
	strstr = ft_free_array(strstr);
	ft_check_duplicates(*a);
	size = ft_add_index(a, argc);
	return (size);
}

int	ft_make_stack(t_list **a, int num, int argc, char **argv)
{
	char	**input;

	input = NULL;
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		argc = 1;
		while (input[argc] != NULL)
			argc++;
		num = ft_create_a_split(a, argc, input);
	}
	else if (argc > 2)
		num = ft_create_a(a, argc, argv);
	return (num);
}

// void	leaks(void)
// {
// 	system("leaks push_swap");
// }

// atexit(leaks);

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		num;

	a = NULL;
	b = NULL;
	num = 0;
	if (argc > 1)
	{
		ft_errors(argc, argv, a);
		num = ft_make_stack(&a, num, argc, argv);
		if (num > 1 && !ft_check_order(a, 'a'))
		{
			if (num <= 6)
				ft_six_nodes(a, b, num);
			num = ((num * 8) / 100) + 1;
			ft_a_to_b(&a, &b, num);
			num = ft_largest_num(b, 'i');
			ft_b_to_a(&a, &b, num);
		}
		ft_free_stack(a);
		ft_free_stack(b);
	}
}
