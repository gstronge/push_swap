/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:35:54 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/13 19:17:03 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order(t_list *list, char c)
{
	if (c == 'a')
	{
		while (list != NULL && list->next != NULL)
		{
			if (list->data > list->next->data)
				return (0);
			list = list->next;
		}
	}
	if (c == 'b')
	{
		while (list != NULL && list->next != NULL)
		{
			if (list->data < list->next->data)
				return (0);
			list = list->next;
		}
	}
	return (1);
}

int	ft_a_to_b(t_list **a, t_list **b, int num)
{
	int	bottom;

	bottom = 0;
	while (*a != NULL)
	{
		if ((*a)->index <= bottom)
		{
			*b = ft_push_to(a, b, 'b');
			*b = ft_rotate(*b, 'b');
			bottom++;
		}
		else if ((*a)->index <= bottom + num)
		{
			*b = ft_push_to(a, b, 'b');
			bottom++;
		}
		else
			*a = ft_rotate(*a, 'a');
	}
	return (bottom);
}

int	ft_b_to_a(t_list **a, t_list **b, int num)
{
	char	direction;

	direction = 'x';
	while (*b != NULL)
	{
		if ((*b)->index == num)
		{
			*a = ft_push_to(b, a, 'a');
		}
		else
		{
			direction = calc_rot_dir(*b, num);
			*b = ft_rot_to_num(*b, num, direction);
			*a = ft_push_to(b, a, 'a');
		}
		num--;
	}
	return (num);
}
