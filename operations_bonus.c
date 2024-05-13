/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:28:56 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/13 15:36:21 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_swap_b(t_list *list)
{
	t_list	*head;

	if (list == NULL || list->next == NULL)
		return (list);
	head = list->next;
	list->next = head->next;
	head->next = list;
	return (head);
}

t_list	*ft_rotate_b(t_list *list)
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
	return (head);
}

t_list	*ft_rev_rotate_b(t_list *list)
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
	return (head);
}

t_list	*ft_push_to_b(t_list **from, t_list **to)
{
	t_list	*pushed_node;

	if (*from == NULL)
		return (*to);
	pushed_node = *from;
	*from = (*from)->next;
	pushed_node->next = *to;
	return (pushed_node);
}
