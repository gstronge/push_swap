/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:55:28 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/13 16:55:51 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "push_swap.h"
# include "libft/libft.h"

void	ft_command_errors(char *command, t_list *a, t_list *b);
void	ft_exucute_doubles(char *command, t_list **a, t_list **b);
void	ft_execute_command(char *command, t_list **a, t_list **b);
char	*ft_reset_command(char *command);
void	ft_result(t_list *a, t_list *b);
t_list	*ft_swap_b(t_list *list);
t_list	*ft_rotate_b(t_list *list);
t_list	*ft_rev_rotate_b(t_list *list);
t_list	*ft_push_to_b(t_list **from, t_list **to);

#endif