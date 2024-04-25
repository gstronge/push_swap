// =========== REMOVE ==================================================================================
#include <stdio.h>
// =========== REMOVE ==================================================================================

#include <stdlib.h>
#include <unistd.h>


// =========== REMOVE ==================================================================================

void	ft_print_all(int *a, int *b, int argc)
{
	printf("=======\n");
	int i = 0;
	while (i < argc - 1)
	{
		printf("%d %d\n", a[i], b[i]);
		i++;
	}
	printf("==========================\n\n");
}
// =========== REMOVE ==================================================================================

int	ft_atoi(char *str, int *a)
{
	int num;
	int negative;
	int i;

	num = 0;
	negative = 1;
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t')) // add other whitespace symbols
		i++;
	if (str[i] == 0)
		return (0);
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
		{
			write(1, "Error", 5);
			free (a);
			exit (0);
		}
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return(num * negative);
}

int	*ft_create_a(int *a, int size, char **argv)
{
	int i;

	i = 0;
	if (!(a = malloc(size * sizeof(int))))
		return (0);
	while (i < size)
	{
		a[i] = ft_atoi(argv[i + 1], a);
		i++;
	}
	return (a);
}

int ft_check_order(int *a, int argc, int size)
{
	int i;

	i = 0;
	int t = argc;
	t++;
	// if (size + 1 != argc)
	// 	return (1);
	
	while (i < (size - 1))
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_ra(int *a, int size, int *b, int argc) // ================== REMOVE , int *b, int argc ========== REMOVE b and argc ==========
{
	int temp;
	int i;

	temp = a[0];
	i = 0;
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = temp;
	write(1, "ra\n", 3);
	ft_print_all(a, b, argc);// ================== REMOVE ========== REMOVE ========== REMOVE ========== REMOVE ==================== 
}

void	ft_sa(int *a, int *b, int argc) // ================== REMOVE , int *b, int argc ========== REMOVE b and argc ========== 
{
	int temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp; 
	write(1, "sa\n", 3);
	ft_print_all(a, b, argc);// ================== REMOVE ========== REMOVE ========== REMOVE ========== REMOVE ==================== 
}

int	ft_largest_num(int *a, int size, int largest_num)
{
	int i;

	i = 0;
	largest_num = -2147483648;
	while (i < size)
	{
		if (a[i] > largest_num)
			largest_num = a[i];
		i++;
	}
	return (largest_num);
}
int	ft_smallest_num(int *a, int size, int smallest_num)
{
	int i;

	i = 0;
	smallest_num = 2147483647;
	while (i < size)
	{
		if (a[i] < smallest_num)
			smallest_num = a[i];
		i++;
	}
	return (smallest_num);
}

int	ft_find_next(int *a, int size, int largest_num, int next_num)
{
	int i;

	next_num = largest_num - 1;
	i = 0;
	while (a[i] != next_num)
	{
		while (i < size)
		{
			if (a[i] == next_num)
				return (next_num);
			i++;
		}
		i = 0;
		next_num--;
	}
	return (next_num);
}

int	ft_pb(int *a, int *b, int size, int argc)
{
	int i;
	int sizeb;

	sizeb = argc - 1 - size;
	size--;
	i = 0;
	while (sizeb > 0)
	{
		b[sizeb] = b[sizeb - 1];
		sizeb--;
	}
	b[0] = a[0];
	while (i < size)
	{
		a[i] = a[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
	ft_print_all(a, b, argc);// ================== REMOVE ========== REMOVE ========== REMOVE ========== REMOVE ==================== 
	return(size);
}

int	ft_pa(int *a, int *b, int size, int argc)
{
	int i;
	int sizeb;

	i = size;
	size++;
	sizeb = argc - 1 - size;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	while (i < sizeb)
	{
		b[i] = b[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
	ft_print_all(a, b, argc);// ================== REMOVE ========== REMOVE ========== REMOVE ========== REMOVE ====================
	return(size);
}

int main(int argc, char **argv)
{
	int *a;
	int *b;
	int size;
	int largest_num;
	int smallest_num;
	int	next_num;

	a = NULL;
	size = argc - 1;
	largest_num = -2147483648;
	smallest_num = 2147483647;
	next_num = 0;
	if (argc > 1)
	{
		a = ft_create_a(a, size, argv);
		if (!(b = malloc(size * sizeof(int))))
			return (0);
	}
	largest_num = ft_largest_num(a, size, largest_num);
	smallest_num = ft_smallest_num(a, size, smallest_num);

// ============ REMOVE =================== REMOVE ================= REMOVE =========================
	int i = 0;
	printf("\n");
	while (i < size)
	{
		printf("%d, ", a[i]);
		i++;
	}
	printf("\n\n");
// ============ REMOVE =================== REMOVE =================== REMOVE =========================

	int counter = 0;

	while (!ft_check_order(a, argc, size))
	{
		if (a[0] > a[1])
		{
			ft_sa(a, b, argc);
			counter++;
		}
		else if (a[0] == smallest_num)
		{
			size = ft_pb(a, b, size, argc);
			smallest_num = ft_smallest_num(a, size, smallest_num);
			counter++;
		}
		else
		{
			ft_ra(a, size, b , argc);
			counter++;
		}
	}
	while (size < argc - 1)
	{
		size = ft_pa(a, b, size, argc);
		counter++;
	}
	
	printf("\n%d\n", counter);

// ============ REMOVE =================== REMOVE =================== REMOVE =========================
	i = 0;
	while (i < size)
	{
		printf("%d, ", a[i]);
		i++;
	}
	printf("\n");
// ============ REMOVE =================== REMOVE =================== REMOVE =========================

	free(a);
	free(b);
}