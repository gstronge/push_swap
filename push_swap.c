/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:57:37 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/06 16:04:59 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// =========== REMOVE ==================================================================================
#include <stdio.h>

void    ft_print_both(t_list *a, t_list *b)
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

static	char	**ft_free_array(char **strstr, int i)
{
	while (i >= 0)
	{
		free(strstr[i]);
		i--;
	}
	free(strstr);
	return (NULL);
}

static	int	ft_strnum(char const *s, char c, int strnum)
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

static	int	ft_copystr(char const *s, char c, char **strstr, int index)
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
			return (ft_free_array(strstr, i));
		i++;
	}
	strstr[i] = NULL;
	return (strstr);
}







void	ft_free_stacks(t_list *a, t_list *b)
{
	t_list	*temp;

	while (a != NULL)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
	while (b != NULL)
	{
		temp = b;
		b = b->next;
		free(temp);
	}
}

void	 ft_print_error(t_list *a, t_list *b)
{
	ft_free_stacks(a, b);
	write(2, "Error\n", 6);
	// FREE STUFF =========================== FREE STUFF ==========================================
	exit (EXIT_FAILURE);
}

int	ft_largest_num(t_list *list)
{
	int largest;

	largest = list->index;
	while (list != NULL)
	{
		if (list->index > largest)
			largest = list->index;
		list = list->next;
	}
	return (largest);
}

int	ft_atoi(char *str, t_list *a, t_list *b)
{
	long	num;
	int		negative;
	int		i;

	num = 0;
	negative = 1;
	i = 0;
	if (str[0] == '0')
		return(0);
	if (str[0] == '-')
	{
		negative = -1;
		num *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		ft_print_error(a, b);
	if (num * negative > INT_MAX || num * negative < INT_MIN)
		ft_print_error(a, b);
	return (num * negative);
}
 
int	ft_add_node_end(t_list *current, int size, char *str, t_list *a)
{
	t_list	*new;

	new = (t_list *)malloc(1 * sizeof(t_list));
	current->next = new;
	new->next = NULL;
	new->data = ft_atoi(str, a, current);
	return (size + 1);
}

int	ft_add_index(t_list **a, int argc)
{
	t_list *current_node;
	int	smallest;
	int	largest;
	int	num;

	current_node = *a;
	smallest = current_node->data;
	largest = current_node->data;
	num = 2;
	while (current_node != NULL)
	{
		if (current_node->data < smallest)
			smallest = current_node->data;
		if (current_node->data > largest)
			largest = current_node->data;
		current_node = current_node->next;
	}

	current_node = *a;
	while (current_node != NULL)
	{
		if (current_node->data == smallest)
			current_node->index = 1;
		current_node = current_node->next;
	}

	int next_smallest;
	while (num < argc)
	{
		current_node = *a;
		next_smallest = largest;
		while (current_node != NULL)
		{
			if (current_node->data > smallest && current_node->data < next_smallest)
				next_smallest = current_node->data;
			current_node = current_node->next;
		}
		current_node = *a;
		while (current_node != NULL)
		{
			if (current_node->data == next_smallest)
			{
				current_node->index = num;
				smallest = next_smallest;
				num++;
			}
			current_node = current_node->next;
		}
	}

	return(num - 1);
}

void	ft_check_duplicates(t_list *a)
{
	t_list	*new_head;
	t_list	*current;
	// int		num;

	new_head = a;
	current = a;
	// num = 0;
	while (new_head)
	{
		current = new_head->next;
		while (current)
		{
			if (new_head->data == current->data)
				ft_print_error(a, current);
			current = current->next;
		}
		new_head = new_head->next;
	}
}

int	ft_create_a(t_list **a, int argc, char **strstr)
{
	t_list	*current;
	int		size;
	int		i;

	*a = (t_list *)malloc(1 * sizeof(t_list));
	if (a == NULL)
		return(0);//===== what happens in this case??? =======================================
	size = 1;
	i = 1;
	current = *a;
	(*a)->data = ft_atoi(&strstr[i][0], *a, current);
	(*a)->next = NULL;
	i++;
	while (i < argc)
	{
		size = ft_add_node_end(current, size, &strstr[i][0], *a);
		current = current->next;
		i++;
	}
	ft_check_duplicates(*a);	
	i = ft_add_index(a, argc);
	//free array -----------------------------------------------------------------------------------------------
	return (i);
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
	t_list    *head;
	t_list    *tail;


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
	t_list    *pushed_node;
 
	if (*from == NULL)
		return (*to);
	pushed_node = *from;
	*from = (*from)->next;
	pushed_node->next = *to;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (pushed_node);//remove this probably =================================================
}

char	calc_rot_dir(t_list *list, int lower, int upper)
{
	t_list	*current_node;
	int		forward;
	int		reverse;
	int		i;

	current_node = list;
	forward = 0;
	reverse = 0;
	i = 0;
	while (current_node != NULL)
	{
		if (current_node->index >= lower && current_node->index <= upper)
			break;
		current_node = current_node->next;
		forward++;
	}
	
	current_node = list;
	while (current_node != NULL)
	{
		if (current_node->index >= lower && current_node->index <= upper)
			reverse = i;
		current_node = current_node->next;
		i++;
	}
	reverse = i - reverse;

	if (forward > reverse)
		return ('r');
	else
		return ('f');
}

t_list	*ft_rot_to_num(t_list *list, int lower, int upper, char direction)
{
	while (list->index < lower || list->index > upper)
	{
		char	a_or_b;
		
		if (lower == upper)// === DO I NEED THIS WITH THE NEW CHANGES TO THE CODE? =============
			a_or_b = 'b';
		else
			a_or_b = 'a';
		if (direction == 'f')
			list = ft_rotate(list, a_or_b);
		else
			list = ft_rev_rotate(list, a_or_b);
	}
	return (list);
}

void	ft_errors(int argc, char **strstr, t_list *a, t_list *b)
{
	int	i;

	i = 1;
	if (strstr[1][0] == '\0')
		exit (EXIT_SUCCESS);
	if (argc < 2 || strstr == NULL)
		ft_print_error(a, b);
	while (strstr[i] != NULL && strstr[i][0] != '\0')
	{
		if ((strstr[i][0] > '9' || strstr[i][0] < '0') && strstr[i][0] != ' ' && strstr[i][0] != '\t' && strstr[i][0] != '-' && strstr[i][0] != '+')
			ft_print_error(a, b);
		if ((strstr[i][0] == '-' || strstr[i][0] == '+') && (strstr[i][1] > '9' || strstr[i][1] < '0'))
			ft_print_error(a, b);
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

t_list	*ft_six_nodes(t_list *a, t_list *b, int num)
{
	if (num <= 3)
		a = ft_three_nodes(a, 'a');
	else
	{
		while (a->next->next != NULL && a->next->next->next != NULL)
		{
			if (a->index <= num - 3)
				b = ft_push_to(&a, &b, 'b');
			else
				a = ft_rotate(a, 'a');
		}
		while (!ft_check_order(a, 'a') || !ft_check_order(b, 'b'))
		{
			if (a->index > a->next->index && b->next != NULL && b->index < b->next->index)
			{
				a = ft_swap(a, 's');
				b = ft_swap(b, 'x');
			}
			else if (a->index > a->next->index)
				a = ft_swap(a, 'a');
			else if (b->next != NULL && b->index < b->next->index)
				b = ft_swap(b, 'b');
			else if (!ft_check_order(a, 'a') && b->next != NULL && !ft_check_order(b, 'b'))
			{
				a = ft_rev_rotate(a, 'r');
				b = ft_rev_rotate(b, 'x');
			}
			else if (!ft_check_order(a, 'a'))
				a = ft_rev_rotate(a, 'a');
			else if (b->next != NULL)
				b = ft_rev_rotate(b, 'b');
		}
		while (b != NULL)
			a = ft_push_to(&b, &a, 'a');
	}
	ft_free_stacks(a, b);
	exit(EXIT_SUCCESS);
}

// void	leaks(void)
// {
// 	system("leaks push_swap");
// }

int main(int argc, char **argv)
{
    t_list	*a;
    t_list	*b;
	int		num;
	char	direction;
	char	**input;

	a = NULL;
	b = NULL;
	// atexit(leaks);
	ft_errors(argc, argv, a, b);
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		argc = 1;
		while (input[argc] != NULL)
			argc++;
		num = ft_create_a(&a, argc, input);
		if (input)
			ft_free_array(input, num);
	}
	else if (argc > 2)
		num = ft_create_a(&a, argc, argv);
	if (argc > 1 && !ft_check_order(a, 'a'))
	{
		if (num <= 6)
			ft_six_nodes(a, b, num);
		num = ((num * 8) / 100) + 1;
		int bottom = 0;
		while (a != NULL)
		{
			if (a->index <= bottom)
			{
				b = ft_push_to(&a, &b, 'b');
				b = ft_rotate(b, 'b');
				bottom++;
			}
			else if (a->index <= bottom + num)
			{
				b = ft_push_to(&a, &b, 'b');
				bottom++;
			}
			else
				a = ft_rotate(a, 'a');
		}
		num = ft_largest_num(b);
		while (b != NULL)
		{
			if (b->index == num)
			{
				a = ft_push_to(&b, &a, 'a');
			}
			else
			{
				direction = calc_rot_dir(b, num, num);
				b = ft_rot_to_num(b, num, num, direction);
				a = ft_push_to(&b, &a, 'a');
			}
			num--;		
		}
	}
	ft_free_stacks(a, b);
}








	// if (argc > 1)
	// {
	// 	num = ft_add_index(&a);
	// 	ft_check_order(a);
	// 	// printf("\n\nadgdsfgfghdfghdhdfhfgfghhfhghgfghdhdfh\n\n");//============ BROKEN =============
	// 	// printf("\nnum = %d\n", num); // ============== REMOVE =========================================================================
	// 	num = ((num * 8) / 100) + 1;
	// 	// num = argc - 1;//need to make a function to calculate this from the linked list since sometimes arc will be a long string
	// 	// num = ft_range(&num) * 14 / 10;
	// 	// if (num == 0)
	// 	// 	num = 1;
		
	// 	// ft_print_both(a, b);// ============ REMOVE =================== REMOVE =================== REMOVE =========================
	// 	// printf("\nnum = %d\n", num); // ============== REMOVE =========================================================================
	// 	int bottom = 0;
	// 	while (a != NULL)
	// 	{
	// 	// printf("\na->index = %d\n", a->index); // ============== REMOVE =========================================================================
	// 		if (a->index <= bottom)
	// 		{
	// 			b = ft_push_to(&a, &b, 'b');
	// 			b = ft_rotate(b, 'b');
	// 			bottom++;
	// 		}
	// 		else if (a->index <= bottom + num)
	// 		{
	// 			b = ft_push_to(&a, &b, 'b');
	// 			bottom++;
	// 			// direction = calc_rot_dir(a, 0, num);
	// 			// if (direction == 'f' && b != NULL && b->next != NULL && num % 2 == 0)
	// 			// {
	// 			// 	a = ft_rotate(a, 'r');
	// 			// 	b = ft_rotate(b, 'x');
	// 			// }
	// 			// else if (num % 2 == 0)
	// 			// 	b = ft_rotate(b, 'b');
	// 			// a = ft_rot_to_num(a, 0, num, direction);
	// 			// b = ft_push_to(&a, &b, 'b');
	// 			// ft_print_both(a, b);// ============ REMOVE =================== REMOVE =================== REMOVE =========================
	// 		}
	// 		else
	// 			a = ft_rotate(a, 'a');
	// 		// if (num % 2 == 0)
	// 		// 	b = ft_rotate(b, 'b');
	// 		// num++;
	// 	// printf("\nbottom = %d\n", bottom); // ============== REMOVE =========================================================================
	// 	// ft_print_both(a, b);// ============ REMOVE =================== REMOVE =================== REMOVE =========================
	// 	}
	// 	num = ft_largest_num(b);
	// 	// printf("\nnum = %d\n", num); // ============== REMOVE =========================================================================
	// 	// ft_print_both(a, b);// ============ REMOVE =================== REMOVE =================== REMOVE =========================
	// 	while (b != NULL)
	// 	{
	// 		if (b->index == num)
	// 		{
	// 			a = ft_push_to(&b, &a, 'a');
	// 		}
	// 		else
	// 		{
	// 			direction = calc_rot_dir(b, num, num);
	// 			b = ft_rot_to_num(b, num, num, direction);
	// 			a = ft_push_to(&b, &a, 'a');
	// 		}
	// 		num--;
	// 		// printf("\nnum = %d\n", num); // ============== REMOVE =========================================================================
	// 		// ft_print_both(a, b);// ============ REMOVE =================== REMOVE =================== REMOVE =========================
	// 	}

	// }
	// // ft_free(a, b);
	// // free(b);