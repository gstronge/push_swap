/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:57:37 by gstronge          #+#    #+#             */
/*   Updated: 2024/04/28 19:57:37 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// =========== REMOVE ==================================================================================
#include <stdio.h>
// =========== REMOVE ==================================================================================

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
 
// =========== PUT IN HEADER FILE ======================================================================
typedef	struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;
// =========== PUT IN HEADER FILE ======================================================================


//  // =========== REMOVE ==================================================================================
//  void    ft_print_both(t_list *a, t_list *b)
//  {    
//      printf("\n============\n");
//      while (a != NULL || b != NULL)
//      {
//          if (a != NULL)
//          {
//              printf("%d\t", a->data);
//              a = a->next;
//          }
//          else
//              printf("x\t");
//          if (b != NULL)
//          {
//              printf("%d\n", b->data);
//              b = b->next;
//          }
//          else
//              printf("x\n");
//      }
//      printf("======================================\n\n");
//  }
//  // =========== REMOVE ==================================================================================

void	ft_print_error(void)
{
	write(1, "Error\n", 6);
	exit (0);
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

int	ft_atoi(char *str)
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
	while (str[i] != '\0')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	if (num * negative > INT_MAX || num * negative < INT_MIN)
		ft_print_error();
	return (num * negative);
}
 
int	ft_add_node_end(t_list *current, int size, char *str)
{
	t_list	*new;

	new = (t_list *)malloc(1 * sizeof(t_list));
	current->next = new;
	new->next = NULL;
	new->data = ft_atoi(str);
	return (size + 1);
}

// ============================= NEW =======================================================================
// ft_next_smallest(a, smallest)
// {
// 	t_list	*head;

// 	head = a;
// 	while (a != NULL)
// 	{
// 		if (a->data == smallest)
// 			return(smallest);
// 	}
// }
// ============================= NEW =======================================================================

// ============================= NEW =======================================================================
int	ft_add_index(t_list **a)
{
	t_list *current_node;
	int	smallest;
	int	largest;
	int	num;

	current_node = *a;
	smallest = current_node->data;
	largest = current_node->data;
	num = 1;
	while (current_node != NULL)
	{
		if (current_node->data < smallest)
			smallest = current_node->data;
		current_node = current_node->next;
	}
	current_node = *a;
	while (current_node != NULL)
	{
		if (current_node->data > largest)
			largest = current_node->data;
		current_node = current_node->next;
	}
	smallest--;//what happens if smallest is the smallest int! ==================================================
	while (smallest != largest)
	{
		current_node = *a;
		smallest++;
		while (current_node != NULL)
		{
			if (current_node->data == smallest)
			{
				current_node->index = num;
				num +=1;
				break;
			}
			current_node = current_node->next;
		}

	}
	return(num - 1); // double check the minus 1 is correct ======================================
}
// ============================= NEW =======================================================================

t_list	*ft_create_a(t_list *a, int argc, char **argv)
{
	t_list    *current;
	int size;
	int i;

	a = (t_list *)malloc(1 * sizeof(t_list));
	if (a == NULL)
		return(NULL);
	size = 1;
	i = 1;
	a->data = ft_atoi(&argv[i][0]);
	a->next = NULL;
	i++;
	current = a;
	while (i < argc)
	{
		size = ft_add_node_end(current, size, &argv[i][0]);
		current = current->next;
		i++;
	}
	// ============================= NEW =======================================================================
	// a = ft_add_index(a, argc);
	// ============================= NEW =======================================================================
	return (a);
}
 
 

// ============================= NEW =======================================================================
t_list	*ft_swap(t_list *list, char c)
{
	t_list	*head;

	head = list->next;
	list->next = head->next;
	head->next = list;
	write(1, "s", 1);
	if (c != 'x')
		write(1, &c, 1);
	write(1, "\n", 1);
	return (list);
}
// ============================= NEW =======================================================================
 
t_list	*ft_rotate(t_list *list, char c)
{
	t_list    *head;
	t_list    *tail;


	if (list == NULL || list->next == NULL)
		return (list);//used to be NULL and I changed it to list ============= might be able to reduce opperations by not writing write!!!
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
		return (list);//used to be NULL and I changed it to list ============= might be able to reduce opperations by not writing write!!!
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
 
	// if (*from == NULL)
	// 	return (*to);
	pushed_node = *from;
	*from = (*from)->next;
	pushed_node->next = *to;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (pushed_node);
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
	
	// printf("forward = %d\n\n", forward); // ==========================================================================
	current_node = list;
	while (current_node != NULL)
	{
		if (current_node->index >= lower && current_node->index <= upper)
			reverse = i;
		current_node = current_node->next;
		i++;
	}
	reverse = i - reverse;
	// printf("reverse = %d\n\n", reverse); // ==========================================================================

	if (forward > reverse)
		return ('r');
	else
	{
		// printf("\n============= NOT YET BROKEN ================ \n"); // ============== REMOVE =========================================================================
		return ('f');
	}
}

t_list	*ft_rot_to_num(t_list *list, int lower, int upper, char direction)
{
	while (list->index < lower || list->index > upper)
	{
		// printf("\n============= NOT YET BROKEN ================ \n"); // ============== REMOVE =========================================================================
		char	a_or_b;
		
		if (lower == upper)
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

void	ft_errors(int argc, char **argv)
{
	// check for larger than int
	// check for non numbers
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i][j] != '\0')
	{
		if ((argv[i][j] > '9' || argv[i][j] < '0') && argv[i][j] != ' ' && argv[i][j] != '-')
			ft_print_error();
		if (argv[i][j] == '-' && (argv[i][j + 1] <= '9' && argv[i][j + 1] >= '0'))
			ft_print_error();
		i++;
	}
}

int main(int argc, char **argv)
{
    t_list	*a;
    t_list	*b;
	int		num;
	char	direction;
 
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		ft_errors(argc, argv);//make error check ====================================================================================
		a = ft_create_a(a, argc, argv);
		num = ft_add_index(&a);
		// printf("\nnum = %d\n", num); // ============== REMOVE =========================================================================
		num = ((num * 8) / 100) + 1;
		// num = argc - 1;//need to make a function to calculate this from the linked list since sometimes arc will be a long string
		// num = ft_range(&num) * 14 / 10;
		// if (num == 0)
		// 	num = 1;
		
		// ft_print_both(a, b);// ============ REMOVE =================== REMOVE =================== REMOVE =========================
		// printf("\nnum = %d\n", num); // ============== REMOVE =========================================================================
		int bottom = 0;
		while (a != NULL)
		{
		// printf("\na->index = %d\n", a->index); // ============== REMOVE =========================================================================
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
				// direction = calc_rot_dir(a, 0, num);
				// if (direction == 'f' && b != NULL && b->next != NULL && num % 2 == 0)
				// {
				// 	a = ft_rotate(a, 'r');
				// 	b = ft_rotate(b, 'x');
				// }
				// else if (num % 2 == 0)
				// 	b = ft_rotate(b, 'b');
				// a = ft_rot_to_num(a, 0, num, direction);
				// b = ft_push_to(&a, &b, 'b');
				// ft_print_both(a, b);// ============ REMOVE =================== REMOVE =================== REMOVE =========================
			}
			else
				a = ft_rotate(a, 'a');
			// if (num % 2 == 0)
			// 	b = ft_rotate(b, 'b');
			// num++;
		// printf("\nbottom = %d\n", bottom); // ============== REMOVE =========================================================================
		// ft_print_both(a, b);// ============ REMOVE =================== REMOVE =================== REMOVE =========================
		}
		num = ft_largest_num(b);
		// printf("\nnum = %d\n", num); // ============== REMOVE =========================================================================
		// ft_print_both(a, b);// ============ REMOVE =================== REMOVE =================== REMOVE =========================
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
			// printf("\nnum = %d\n", num); // ============== REMOVE =========================================================================
			// ft_print_both(a, b);// ============ REMOVE =================== REMOVE =================== REMOVE =========================
		}

	}
	// ft_free(a, b);
	// free(b);
}
