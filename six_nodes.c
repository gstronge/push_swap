/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:28:46 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/07 12:28:47 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_three_nodes(t_list *list, char c)
{
	while (!ft_check_order(list, c))
	{
		if (list->index > list->next->index)
			list = ft_swap(list, c);
		else
			list = ft_rev_rotate(list, c);
	}
	return (list);
}

void	ft_push_smallest(t_list **a, t_list **b, int num)
{
	while ((*a)->next->next != NULL && (*a)->next->next->next != NULL)
	{
		if ((*a)->index <= num - 3)
			*b = ft_push_to(a, b, 'b');
		else
			*a = ft_rotate(*a, 'a');
	}
}

void	ft_arrange_lists(t_list **a, t_list **b)
{
	while (!ft_check_order(*a, 'a') || !ft_check_order(*b, 'b'))
	{
		if ((*a)->index > (*a)->next->index && (*b)->next != NULL
			&& (*b)->index < (*b)->next->index)
		{
			*a = ft_swap(*a, 's');
			*b = ft_swap(*b, 'x');
		}
		else if ((*a)->index > (*a)->next->index)
			*a = ft_swap(*a, 'a');
		else if ((*b)->next != NULL && (*b)->index < (*b)->next->index)
			*b = ft_swap(*b, 'b');
		else if (!ft_check_order(*a, 'a') && (*b)->next != NULL
			&& !ft_check_order(*b, 'b'))
		{
			*a = ft_rev_rotate(*a, 'r');
			*b = ft_rev_rotate(*b, 'x');
		}
		else if (!ft_check_order(*a, 'a'))
			*a = ft_rev_rotate(*a, 'a');
		else if ((*b)->next != NULL)
			*b = ft_rev_rotate(*b, 'b');
	}
}

t_list	*ft_six_nodes(t_list *a, t_list *b, int num)
{
	if (num <= 3)
		a = ft_three_nodes(a, 'a');
	else
	{
		ft_push_smallest(&a, &b, num);
		ft_arrange_lists(&a, &b);
		while (b != NULL)
			a = ft_push_to(&b, &a, 'a');
	}
	ft_free_stack(a);
	exit(EXIT_SUCCESS);
}
