/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:55:28 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/07 14:34:51 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

char	**ft_free_array(char **strstr);
int		ft_strnum(char const *s, char c, int strnum);
int		ft_copystr(char const *s, char c, char **strstr, int index);
char	**ft_split(char const *s, char c);

t_list	*ft_swap(t_list *list, char c);
t_list	*ft_rotate(t_list *list, char c);
t_list	*ft_rev_rotate(t_list *list, char c);
t_list	*ft_push_to(t_list **from, t_list **to, char c);

void	ft_free_stack(t_list *list);
void	ft_print_error(t_list *a);
void	ft_print_error_split(t_list *a, char **strstr);
void	ft_check_duplicates(t_list *a);
void	ft_errors(int argc, char **strstr, t_list *a);

t_list	*ft_three_nodes(t_list *list, char c);
void	ft_push_smallest(t_list **a, t_list **b, int num);
void	ft_arrange_lists(t_list **a, t_list **b);
t_list	*ft_six_nodes(t_list *a, t_list *b, int num);

int		ft_check_order(t_list *list, char c);
int		ft_a_to_b(t_list **a, t_list **b, int num);
int		ft_b_to_a(t_list **a, t_list **b, int num);

int		ft_forward_steps(t_list *list, int lower, int upper, int forward);
int		ft_reverse_steps(t_list *list, int lower, int upper, int reverse);
t_list	*ft_rot_to_num(t_list *list, int num, char direction);
char	calc_rot_dir(t_list *list, int lower, int upper);

int		ft_largest_num(t_list *list, char c);
int		ft_smallest_num(t_list *list);
int		ft_next_smallest(t_list *a, int min, int next_min, int largest);
int		ft_add_nums(t_list *a, int next_min, int num);
int		ft_add_index(t_list **a, int argc);

int		ft_atoi(char *str, t_list *a);
void	ft_add_node(t_list *current, char *str, t_list *a);
int		ft_atoi_split(char *str, t_list *a, char **strstr);
void	ft_add_node_split(t_list *current, char *str, t_list *a, char **strstr);

int		ft_create_a(t_list **a, int argc, char **strstr);
int		ft_create_a_split(t_list **a, int argc, char **strstr);
int		ft_make_stack(t_list **a, int num, int argc, char **argv);

#endif