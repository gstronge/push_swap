/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:48:34 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/07 14:35:46 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_largest_num(t_list *list, char c)
{
	int	largest;

	largest = 0;
	if (c == 'i')
	{
		largest = list->index;
		while (list != NULL)
		{
			if (list->index > largest)
				largest = list->index;
			list = list->next;
		}
	}
	else if (c == 'd')
	{
		largest = list->data;
		while (list != NULL)
		{
			if (list->data > largest)
				largest = list->data;
			list = list->next;
		}
	}
	return (largest);
}

int	ft_smallest_num(t_list *list)
{
	int	smallest;

	smallest = list->data;
	while (list != NULL)
	{
		if (list->data < smallest)
			smallest = list->data;
		list = list->next;
	}
	return (smallest);
}

int	ft_next_smallest(t_list *a, int smallest, int next_min, int largest)
{
	next_min = largest;
	while (a != NULL)
	{
		if (a->data > smallest && a->data < next_min)
			next_min = a->data;
		a = a->next;
	}
	return (next_min);
}

int	ft_add_nums(t_list *a, int next_min, int num)
{
	while (a != NULL)
	{
		if (a->data == next_min)
		{
			a->index = num;
			num++;
			break ;
		}
		a = a->next;
	}
	return (num);
}

int	ft_add_index(t_list **a, int argc)
{
	int		num;
	int		smallest;
	int		largest;
	int		next_min;
	t_list	*current_node;

	current_node = *a;
	num = 1;
	smallest = ft_smallest_num(*a);
	largest = ft_largest_num(*a, 'd');
	while (current_node != NULL)
	{
		if (current_node->data == smallest)
			current_node->index = num;
		current_node = current_node->next;
	}
	num++;
	while (num < argc)
	{
		next_min = ft_next_smallest(*a, smallest, next_min, largest);
		num = ft_add_nums(*a, next_min, num);
		smallest = next_min;
	}
	return (num - 1);
}
