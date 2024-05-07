/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:28:56 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/07 12:28:57 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_swap(t_list *list, char c)
{
	t_list	*head;

	if (list == NULL || list->next == NULL)
		return (list);
	head = list->next;
	list->next = head->next;
	head->next = list;
	if (c != 'x')
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	return (head);
}

t_list	*ft_rotate(t_list *list, char c)
{
	t_list	*head;
	t_list	*tail;

	if (list == NULL || list->next == NULL)
		return (list);
	tail = list;
	head = list->next;
	while (list->next != NULL)
		list = list->next;
	list->next = tail;
	tail->next = NULL;
	if (c != 'x')
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	return (head);
}

t_list	*ft_rev_rotate(t_list *list, char c)
{
	t_list	*head;
	t_list	*tail;

	if (list == NULL || list->next == NULL)
		return (list);
	tail = list;
	while (tail->next->next != NULL)
		tail = tail->next;
	head = tail->next;
	head->next = list;
	tail->next = NULL;
	if (c != 'x')
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	return (head);
}

t_list	*ft_push_to(t_list **from, t_list **to, char c)
{
	t_list	*pushed_node;

	if (*from == NULL)
		return (*to);
	pushed_node = *from;
	*from = (*from)->next;
	pushed_node->next = *to;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (pushed_node);
}
