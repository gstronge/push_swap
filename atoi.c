/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:50:38 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/10 19:40:43 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_ps(char *str, t_list *a)
{
	long	num;
	int		negative;
	int		i;

	num = 0;
	negative = 1;
	i = 0;
	if (str[0] == '+')
		i++;
	if (str[0] == '-')
	{
		negative = -1;
		num *= -1;
		i++;
	}
	if (str[i] == '0')
		return (0);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	if (str[i] != '\0' || num * negative > INT_MAX || num * negative < INT_MIN)
		ft_print_error(a);
	return (num * negative);
}

void	ft_add_node(t_list *current, char *str, t_list *a)
{
	t_list	*new;

	new = (t_list *)malloc(1 * sizeof(t_list));
	current->next = new;
	new->next = NULL;
	new->data = ft_atoi_ps(str, a);
}

int	ft_atoi_split(char *str, t_list *a, char **strstr)
{
	long	num;
	int		negative;
	int		i;

	num = 0;
	negative = 1;
	i = 0;
	if (str[0] == '+')
		i++;
	if (str[0] == '-')
	{
		negative = -1;
		num *= -1;
		i++;
	}
	if (str[i] == '0')
		return (0);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	if (str[i] != '\0' || num * negative > INT_MAX || num * negative < INT_MIN)
		ft_print_error_split(a, strstr);
	return (num * negative);
}

void	ft_add_node_split(t_list *current, char *str, t_list *a, char **strstr)
{
	t_list	*new;

	new = (t_list *)malloc(1 * sizeof(t_list));
	current->next = new;
	new->next = NULL;
	new->data = ft_atoi_split(str, a, strstr);
}
