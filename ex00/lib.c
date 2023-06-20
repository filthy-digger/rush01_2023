#include <stdbool.h>
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "includes.h"

void	ft_putnbr_aux(int n)
{
	int		r;
	int		q;
	char	c;

	q = n / 10;
	r = n % 10;
	if (q > 0)
		ft_putnbr_aux(q);
	c = (char) (r + 48);
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (-2147483648 == nb)
		write (1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		ft_putnbr_aux(nb);
	}
}

size_t ft_strlen(char *str)
{
	char *save;

	save = str;
	while (str != NULL && *str != '\0')
		str++;
	return (str - save);
}

//ft_power takes:
//a signed integer base - [b]
//an unsigned exponent - [e]
//
//returns the result of exponentiation of b to the e as a signed integer
//
//doesn't handle overflow
int ft_power(int b, unsigned int e)
{
	if (e == 0)
		return 1;
	else
		return b * (ft_power(b, e - 1));
}

unsigned int factorial(unsigned int n)
{
	if (n == 1)
		return n;
	else
		return n * factorial(n - 1);
}

void swap_int(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int *rev_int_arr(int *arr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		swap_int(arr + i, arr + size - 1);
		size--;
		i++;
	}
	return arr;
}

//permute takes:
//a pointer to the previous permutation - [prev]
//a pointer to store of the next permutation - [next]
//the size of the sequence to of permutation - [size]
//
//returns a pointer to the start of [next]
//
//assumes proper malloc of prev and next
int *permute(int *prev, int *next, size_t size)
{
	int *save_lower;
	int *save_upper;

	save_lower = NULL;
	save_upper = NULL;
	size_t k = 0;
	if (size == 0)
		return NULL;
	while (size - k)
	{
		if (((size - 1) - k) && *(prev + k) < *(prev + k + 1))
		{
			save_lower = prev + k;
			save_upper = prev + k + 1;
		} else if (save_lower != NULL && *save_lower < *(prev + k))
			save_upper = prev + k;
		*(next + k) = *(prev + k);
		k++;
	}
	if (save_lower != NULL)
	{
		*(next + (save_lower - prev)) = *save_upper;
		*(next + (save_upper - prev)) = *save_lower;
		rev_int_arr(next + (save_lower - prev) + 1,
					size - (save_lower - prev) - 1);
	}
	return next;
}

// print numbers (char) from int
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstrn(char *str, size_t size)
{
	while(size--)
		ft_putchar(*(str++));
}

void	ft_putstr(char *str)
{
	size_t size;
	size = ft_strlen(str);
	ft_putstrn(str, size);
}

void rev_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		swap_int(&tab[i], &tab[j]);
		i++;
		j--;
	}
}


// takes an 1 dimensional array of int as input
// calculates visible boxes for view
//
// return - 1 == error
// return 1, 2, 3,4 == number of visible boxes
int count_view(int *ch)
{
	int i = 0;
	int count = 0;

	if (ch[i] + ch[i + 1] + ch[i + 2] + ch[i + 3] != 10)
		return -1;

	if (ch[i] == 4)
		return 1;

	if (((ch[i] > ch[i + 1]) && (ch[i] < ch[i + 2]) && (ch[i + 2] > ch[i + 3]))
		|| ((ch[i] > ch[i + 1]) && (ch[i] > ch[i + 2]) && (ch[i] < ch[i + 3]))
		|| ((ch[i] < ch[i + 1]) && (ch[i + 1] > ch[i + 2]) &&
			(ch[i + 1] > ch[i + 3])))
		return 2;

	if ((ch[i] > ch[i + 1] && ch[i] > ch[i + 2] && ch[i + 2] < ch[i + 3])
		|| (ch[i] < ch[i + 1] && ch[i + 1] > ch[i + 2] && ch[i + 1] < ch[i + 3])
		|| (ch[i] > ch[i + 1] && ch[i + 1] < ch[i + 2] && ch[i + 1] < ch[i + 3])
		||
		(ch[i] < ch[i + 1] && ch[i + 1] < ch[i + 2] && ch[i + 2] > ch[i + 3]))
		return 3;

	if (ch[i] < ch[i + 1] && ch[i + 1] < ch[i + 2] && ch[i + 2] < ch[i + 3])
		return 4;
	return -1;
}


// takes 2d array as input, and output array to transpose to
//
// yield a tranposed array
int **transpose_matrix(int **matrix, int **matrix_transpose,
					   size_t rows, size_t cols)
{
	size_t j;
	size_t i;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			matrix_transpose[i][j] = matrix[j][i];
			j++;
		}
		i++;
	}
	return (matrix_transpose);
}

void print_matrix(int **arr, size_t rows, size_t cols)
{
	size_t i;
	size_t j = 0;

	while (j < rows)
	{
		i = 0;
		while (i < cols)
		{
			ft_putnbr(arr[j][i]);
			if (i < cols - 1)
				write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int **malloc_matrix_rows(size_t rows)
{
	int	**matrix;
	matrix = (int **) malloc(rows * sizeof(int *));
	if (matrix == NULL)
		return NULL;
	return matrix;
}

int **malloc_matrix(size_t cols, size_t rows)
{
	int	**matrix;

	matrix = malloc_matrix_rows(rows);
	if (matrix == NULL)
		return NULL;
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = (int *) malloc(cols * sizeof(int));
		if (matrix[i] == NULL)
			return NULL;
	}
	return matrix;
}

int **gen_permutations(size_t size)
{
	size_t	cols;
	size_t	rows;
	int		**matrix;

	cols = size;
	rows = factorial(size);
	matrix = malloc_matrix(cols, rows);

	if (matrix == NULL)
		return NULL;

	for (size_t i = 0; i < rows; i++)
	{
		if (i == 0)
			for (size_t j = 0; j < cols; j++)
				matrix[i][j] = j + 1;
		else
			permute(matrix[i - 1], matrix[i], cols);
	}
	return matrix;
}

int **gen_solution(size_t size, int *input)
{
	size_t permutations;
	int **solution_matrix;
	int **permutation_matrix;
	int **solution_matrix_transpose;
	int *views;


	views = malloc(ft_power(size, 2) * sizeof(int));
	permutation_matrix = gen_permutations(size);
	solution_matrix = malloc_matrix_rows(size);
	solution_matrix_transpose = malloc_matrix(size, size);
	permutations = factorial(size);
	for (int i = 0; i < permutations; i++)
	{
		solution_matrix[0] = permutation_matrix[i];
		for (int j = 0; j < permutations; j++)
		{
			solution_matrix[1] = permutation_matrix[j];
			for (int k = 0; k < permutations; k++)
			{
				solution_matrix[2] = permutation_matrix[k];
				for (int l = 0; l < permutations; l++)
				{
					solution_matrix[3] = permutation_matrix[l];
					transpose_matrix(solution_matrix,
									 solution_matrix_transpose, 4, 4);
					if ((sudoku_alt(solution_matrix, size)
						 && (sudoku_alt(solution_matrix_transpose, size))))
					{
						count_rows(solution_matrix, views);
						if (checker(views, input))
							return solution_matrix;
					}
				}
			}
		}
	}
	return NULL;
}

void print_arr(int *arr, size_t size)
{
	size_t i = 0;
	while (i < size)
		ft_putnbr(arr[i++]);
}

void puterr(char *error_detail)
{
	if (error_detail != NULL)
	{
		char *errormsg = "error:\n";
		write(2, errormsg, ft_strlen(errormsg));
		write(2, error_detail, ft_strlen(error_detail));
	} else
	{
		char *errormsg = "error\n";
		write(2, errormsg, ft_strlen(errormsg));
	}
}


//count_spc takes a NUL-terminated string - "str"
//returns the number of space(ASCII 32, ' ') chars in the string
int count_spc(char *str)
{
	int count = 0;
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			count++;
		}
		i++;
	}
	return count;
}


int *parse_uinput(char *str, unsigned int n)
{
	size_t format_spc_count;
	size_t format_length;
	size_t i;
	int	*uinput;

	uinput = malloc(ft_power(n, 2) * sizeof(int));
	format_spc_count = ft_power(n, 2) - 1;
	format_length = ft_power(n, 2) + format_spc_count;
	i = 0;
	if (ft_strlen(str) == format_length && count_spc(str) == format_spc_count)
	{
		while (i < format_length)
		{
			if ((i % 2 == 0) && ('0' < str[i]) && (str[i] <= n + 48))
			{
				uinput[i/2] = str[i] - 48;
			}
			else if (!(( i % 2 == 1) && (str[i] == ' ')))
			{
				free(uinput);
				return NULL;
			}
			i++;
		}
		return uinput;
	} else
	{
		free(uinput);
		return NULL;
	}
}

// compare results and user-input
// returns 0 if perfect match
// return != 0 when no match
int checker(int input[16], int result[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (count == 0 && i < 16)
	{
		count += input[i] - result[i];
		i++;
	}
	return (count);
}

// count nbr of boxes seen from all POV (CU CD RR RL)
// writes results to "results" array in main
void count_rows(int **arr, int *dest_arr)
{
	int i = 0;
	int j = 0;

	size_t size = 4;
	int *result_counter = malloc(size * sizeof(int));

	// create tranposed array with column values to check
	int **transp_arr = malloc_matrix(size, size);
	transpose_matrix(arr, transp_arr, 4, 4);

	// count C-U
	j = 0;
	int k = 0;
	while (j < 4)
		result_counter[k++] = count_view(transp_arr[j++]);

	// count C-D (reverse tab)
	j = 0;
	while (j < 4)
	{
		rev_tab(transp_arr[j], 4);
		result_counter[k++] = count_view(transp_arr[j++]);
	}

	// count R-L
	j = 0;
	while (j < 4)
		result_counter[k++] = count_view((arr[j++]));

	// count R-R (reverse tab)
	j = 0;
	while (j < 4)
	{
		rev_tab(arr[j], 4);
		result_counter[k++] = count_view(arr[j++]);
	}

	i = 0;
	while (i < 16)
	{
		dest_arr[i] = result_counter[i];
		i++;
	}
}

bool sudoku_alt(int **matrix, size_t n)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			k = j + 1;
			while (k < n)
			{
				if (matrix[i][j] == matrix[i][k])
					return false;
				k++;
			}
			j++;
		}
		i++;
	}
	return true;
}



