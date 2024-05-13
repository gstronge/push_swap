/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:57:37 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/13 16:21:22 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
