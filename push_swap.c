/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:37:59 by gstronge          #+#    #+#             */
/*   Updated: 2024/04/26 11:21:38 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// =========== REMOVE ==================================================================================
#include <stdio.h>
// =========== REMOVE ==================================================================================

#include <stdlib.h>
#include <unistd.h>

// =========== PUT IN HEADER FILE ======================================================================
typedef	struct s_list
{
	int				data;
	int				size; // am I using this? =======================================================
	struct s_list	*next;
}	t_list;
// =========== PUT IN HEADER FILE ======================================================================

// =========== REMOVE ==================================================================================
void	ft_print_both(t_list *a, t_list *b)
{	
	printf("\n=========\n");
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			printf("%d  ", a->data);
			a = a->next;
		}
		else
			printf("x  ");
		if (b != NULL)
		{
			printf("%d\n", b->data);
			b = b->next;
		}
		else
			printf("x\n");
	}
	printf("======================================\n\n");
}
// =========== REMOVE ==================================================================================

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

t_list	*ft_create_a(t_list *a, int argc, char **argv)
{
	t_list	*current;
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
	return (a);
}

t_list	*ft_rotate(t_list *list, char c)
{
	t_list	*head;
	t_list	*tail;

	if (list == NULL || list->next == NULL)
		return (NULL);
	tail = list;
	head = list->next;
	while (list->next != NULL)
		list = list->next;
	list->next = tail;
	tail->next = NULL;
	write(1, "r", 1);
	write(1, &c, 1);
	return (head);
}

t_list	*ft_swap(t_list *list, char c)
{
	int		temp;

	if (list == NULL || list->next == NULL)
		return (NULL);
	temp = list->data;
	list->data = list->next->data;
	list->next->data = temp;
	write(1, "s", 1);
	write(1, &c, 1);
	return (list);
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
	return (pushed_node);
}

t_list	*ft_rev_rotate(t_list *list, char c)
{
	t_list	*head;
	t_list	*tail;

	if (list == NULL || list->next == NULL)
		return (NULL);
	tail = list;
	while (tail->next->next != NULL)
		tail = tail->next;
	head = tail->next;
	head->next = list;
	tail->next = NULL;
	write(1, "rr", 2);
	write(1, &c, 1);
	return (head);
}
int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int counter = 0;// ============ REMOVE =================== REMOVE =================== REMOVE =========================

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		a = ft_create_a(a, argc, argv);
	}

// ============ REMOVE =================== REMOVE ================= REMOVE =========================
	ft_print_both(a, b);
// // ============ REMOVE =================== REMOVE =================== REMOVE ====================

		b = ft_push_to(&a, &b, 'b');

// ============ REMOVE =================== REMOVE ================= REMOVE =========================
	ft_print_both(a, b);
// // ============ REMOVE =================== REMOVE =================== REMOVE =========================


	printf("\n%d\n", counter);// ============ REMOVE =================== REMOVE =================== REMOVE ========================= 


	ft_free(a, b);
	// free(b);
}