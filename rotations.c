/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:26:45 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/13 19:28:06 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_forward_steps(t_list *list, int num, int forward)
{
	while (list != NULL)
	{
		if (list->index == num)
			break ;
		list = list->next;
		forward++;
	}
	return (forward);
}

int	ft_reverse_steps(t_list *list, int num, int reverse)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		if (list->index == num)
			reverse = i;
		list = list->next;
		i++;
	}
	reverse = i - reverse;
	return (reverse);
}

t_list	*ft_rot_to_num(t_list *list, int num, char direction)
{
	while (list->index != num)
	{
		if (direction == 'f')
			list = ft_rotate(list, 'b');
		else
			list = ft_rev_rotate(list, 'b');
	}
	return (list);
}

char	calc_rot_dir(t_list *list, int num)
{
	int	forward;
	int	reverse;

	forward = 0;
	reverse = 0;
	forward = ft_forward_steps(list, num, forward);
	reverse = ft_reverse_steps(list, num, reverse);
	if (forward > reverse)
		return ('r');
	else
		return ('f');
}
