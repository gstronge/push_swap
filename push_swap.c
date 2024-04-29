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

 
//  int    ft_largest_num(t_list *a)
//  {
//      int largest;
 
//      largest = -2147483648;
//      while (a != NULL)
//      {
//          if (a->data > largest)
//              largest = a->data;
//          a = a->next;
//      }
//      return (largest);
//  }
 
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
t_list	*ft_add_index(t_list *a)
{
	t_list *current_node;
	int	smallest;
	int	largest;
	int	num;

	current_node = a;
	smallest = current_node->data;
	largest = current_node->data;
	num = 1;
	while (current_node != NULL)
	{
		if (current_node->data < smallest)
			smallest = current_node->data;
		current_node = current_node->next;
	}
	current_node = a;
	while (current_node != NULL)
	{
		if (current_node->data > largest)
			largest = current_node->data;
		current_node = current_node->next;
	}
	smallest--;//what happens if smallest is the smallest int! ==================================================
	while (smallest != largest)
	{
		current_node = a;
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
	return(a);
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

	write(1, "r", 1);// move all writes to bottom of functions!
	if (c != 'x')
		write(1, &c, 1);
	write(1, "\n", 1);
	if (list == NULL || list->next == NULL)
		return (list);//used to be NULL and I changed it to list ============= might be able to reduce opperations by not writing write!!!
	tail = list;
	head = list->next;
	while (list->next != NULL)
		list = list->next;
	list->next = tail;
	tail->next = NULL;
	return (head);
}
 
 // t_list    *ft_rev_rotate(t_list *list, char c)
 // {
 //     t_list    *head;
 //     t_list    *tail;
 
 //     if (list == NULL || list->next == NULL)
 //         return (NULL);
 //     tail = list;
 //     while (tail->next->next != NULL)
 //         tail = tail->next;
 //     head = tail->next;
 //     head->next = list;
 //     tail->next = NULL;
 //     write(1, "rr", 2);
 //     write(1, &c, 1);
 //     return (head);
 // }
 
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

int	ft_check_binary(t_list *a, int shift)
{
	int	comp;
	int	temp;

	comp = 1;
	temp = a->index >> shift;
	return (temp & comp);//remove the temp from this function when i am sure everyt hing works fine =======================================
}

int	ft_check_sorted(t_list *a)
{
	if (a == NULL)
		return (0);
	while (a != NULL && a->next != NULL)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
    t_list	*a;
    t_list	*b;
	int		shift;
	int		i;
 
	a = NULL;
	b = NULL;
	shift = 0;
	i = 1;
	//ft_errors(argc, argv); //make error check ====================================================================================
	if (argc > 1)
	{
		a = ft_create_a(a, argc, argv);
		a = ft_add_index(a);
		while (!ft_check_sorted(a))
		{
			if (b == NULL)
			{
				while (i < argc)
				{
					if (!ft_check_binary(a, shift))//one of these with a ! the other without ========================================
						b = ft_push_to(&a, &b, 'b');
					else 
						a = ft_rotate(a, 'a');
					i++;
				}
				while (b != NULL)
				{
					a = ft_push_to(&b, &a, 'a');
				}
			}
			shift++;
			i = 1;
		}
	}
	// ft_free(a, b);
	// free(b);
}
