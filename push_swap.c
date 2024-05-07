/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:57:37 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/07 11:36:32 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// =========== REMOVE ==================================================================================
#include <stdio.h>

void	ft_print_both(t_list *a, t_list *b)
{
	printf("\n============\n");
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			printf("%d/%d\t\t", a->data, a->index);
			a = a->next;
		}
		else
			printf("x\t");
		if (b != NULL)
		{
			printf("%d/%d\n", b->data, b->index);
			b = b->next;
		}
		else
			printf("x\n");
	}
	printf("======================================\n\n");
}
// =========== REMOVE ==================================================================================

static char	**ft_free_array(char **strstr)
{
	int	i;

	i = 1;
	free(strstr[0]);
	while (strstr[i] != NULL)
	{
		free(strstr[i]);
		i++;
	}
	free(strstr[i]);
	free(strstr);
	return (NULL);
}

static int	ft_strnum(char const *s, char c, int strnum)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (0);
	if (c == '\0' && i > 0)
		return (1);
	strnum = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
			strnum++;
		if (s[i] == c && s[i + 1] == '\0')
			strnum--;
		i++;
	}
	return (strnum);
}

static int	ft_copystr(char const *s, char c, char **strstr, int index)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	strstr[index] = (char *)malloc((i + 1) * sizeof(char));
	if (strstr[index] == NULL)
		return (i);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		strstr[index][i] = s[i];
		i++;
	}
	strstr[index][i] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		strnum;
	char	**strstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	strnum = 0;
	strnum = ft_strnum(s, c, strnum);
	strstr = (char **)malloc((strnum + 2) * sizeof(char *));
	if (strstr == NULL)
		return (NULL);
	strstr[i] = NULL;
	i++;
	while (i <= strnum)
	{
		while (s[j] == c)
			j++;
		j = j + ft_copystr(s + j, c, strstr, i);
		if (strstr[i] == NULL)
			return (ft_free_array(strstr));
		i++;
	}
	strstr[i] = NULL;
	return (strstr);
}

void	ft_free_stack(t_list *list)
{
	t_list	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	ft_print_error(t_list *a)
{
	ft_free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_print_error_split(t_list *a, char **strstr)
{
	ft_free_array(strstr);
	ft_free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

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

int	ft_atoi(char *str, t_list *a)
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

int	ft_add_node(t_list *current, int size, char *str, t_list *a)
{
	t_list	*new;

	new = (t_list *)malloc(1 * sizeof(t_list));
	current->next = new;
	new->next = NULL;
	new->data = ft_atoi(str, a);
	return (size + 1);
}

int	ft_next_smallest(t_list *a, int smallest, int next_smallest, int largest)
{
	next_smallest = largest;
	while (a != NULL)
	{
		if (a->data > smallest && a->data < next_smallest)
			next_smallest = a->data;
		a = a->next;
	}
	return (next_smallest);
}

int	ft_add_nums(t_list *a, int next_smallest, int num)
{
	while (a != NULL)
	{
		if (a->data == next_smallest)
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
	int		next_smallest;
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
		next_smallest = ft_next_smallest(*a, smallest, next_smallest, largest);
		num = ft_add_nums(*a, next_smallest, num);
		smallest = next_smallest;
	}
	return (num - 1);
}

void	ft_check_duplicates(t_list *a)
{
	t_list	*new_head;
	t_list	*current;

	new_head = a;
	current = a;
	while (new_head)
	{
		current = new_head->next;
		while (current)
		{
			if (new_head->data == current->data)
				ft_print_error(a);
			current = current->next;
		}
		new_head = new_head->next;
	}
}

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
		// remove this probably =================================================
}

int	ft_forward_steps(t_list *list, int lower, int upper, int forward)
{
	while (list != NULL)
	{
		if (list->index >= lower && list->index <= upper)
			break ;
		list = list->next;
		forward++;
	}
	return (forward);
}

int	ft_reverse_steps(t_list *list, int lower, int upper, int reverse)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		if (list->index >= lower && list->index <= upper)
			reverse = i;
		list = list->next;
		i++;
	}
	reverse = i - reverse;
	return (reverse);
}

char	calc_rot_dir(t_list *list, int lower, int upper)
{
	int	forward;
	int	reverse;

	forward = 0;
	reverse = 0;
	forward = ft_forward_steps(list, lower, upper, forward);
	reverse = ft_reverse_steps(list, lower, upper, reverse);
	if (forward > reverse)
		return ('r');
	else
		return ('f');
}

void	ft_errors(int argc, char **strstr, t_list *a)
{
	int	i;

	i = 1;
	if (strstr[1][0] == '\0')
		exit(EXIT_SUCCESS);
	if (argc < 2 || strstr == NULL)
		ft_print_error(a);
	while (strstr[i] != NULL && strstr[i][0] != '\0')
	{
		if ((strstr[i][0] > '9' || strstr[i][0] < '0') && strstr[i][0] != ' '
			&& strstr[i][0] != '\t' && strstr[i][0] != '-'
			&& strstr[i][0] != '+')
			ft_print_error(a);
		if ((strstr[i][0] == '-' || strstr[i][0] == '+') && (strstr[i][1] > '9'
				|| strstr[i][1] < '0'))
			ft_print_error(a);
		i++;
	}
}

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

int	ft_create_a(t_list **a, int argc, char **strstr)
{
	t_list	*current;
	int		size;
	int		i;

	*a = (t_list *)malloc(1 * sizeof(t_list));
	if (a == NULL)
		return (0);
			//===== what happens in this case??? =======================================
	size = 1;
	i = 1;
	current = *a;
	(*a)->data = ft_atoi(&strstr[i][0], *a);
	(*a)->next = NULL;
	i++;
	while (i < argc)
	{
		size = ft_add_node(current, size, &strstr[i][0], *a);
		current = current->next;
		i++;
	}
	ft_check_duplicates(*a);
	i = ft_add_index(a, argc);
	return (i);
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

int	ft_create_a_split(t_list **a, int argc, char **strstr)
{
	t_list	*current;
	int		i;

	*a = (t_list *)malloc(1 * sizeof(t_list));
	if (a == NULL)
		return (0);
			//===== what happens in this case??? =======================================
	i = 1;
	current = *a;
	(*a)->data = ft_atoi_split(&strstr[i][0], *a, strstr);
	(*a)->next = NULL;
	i++;
	while (i < argc)
	{
		ft_add_node_split(current, &strstr[i][0], *a, strstr);
		current = current->next;
		i++;
	}
	strstr = ft_free_array(strstr);
	ft_check_duplicates(*a);
	i = ft_add_index(a, argc);
	return (i);
}

int	ft_make_stack(t_list **a, int num, int argc, char **argv)
{
	char	**input;

	input = NULL;
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		argc = 1;
		while (input[argc] != NULL)
			argc++;// argc will be 1 less than the no of things in the list as the last array is null
		num = ft_create_a_split(a, argc, input);
	}
	else if (argc > 2)
		num = ft_create_a(a, argc, argv);
	return (num);
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
			direction = calc_rot_dir(*b, num, num);
			*b = ft_rot_to_num(*b, num, direction);
			*a = ft_push_to(b, a, 'a');
		}
		num--;
	}
	return (num);
}

// void	leaks(void)
// {
// 	system("leaks push_swap");
// }
// atexit(leaks);

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		num;

	a = NULL;
	b = NULL;
	num = 0;
	ft_errors(argc, argv, a);
	num = ft_make_stack(&a, num, argc, argv);
	if (argc > 1 && !ft_check_order(a, 'a'))
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
