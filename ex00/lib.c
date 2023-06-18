#include <stdbool.h>
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "includes.h"

void print_matrix(int **arr, size_t rows, size_t cols);

size_t	ft_strlen(char *str)
{
	char	*save;

	save = str;
	while(str != NULL && *str != '\0')
		str++;
	return (str - save); 
}

void	ft_putstr(char *str)
{
	while(str && *str)
		write(1, (str++), 1);
}

//pow takes:
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

unsigned int choose(unsigned int n, unsigned int k)
{
	if (k == 0 || n < k)
		return 0;
	else
		return factorial(n) / (factorial(n-k) * factorial(k));
}

void	swap_int(int*	ptr1, int* ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int*	rev_int_arr(int *arr, size_t size)
{
	int* save = arr;
	for(size_t i = 0; i < size ; size--, i++)
		swap_int(arr+i,arr+size-1);
	return save;
}

//void	swap(void*	ptr1, void* ptr2, size_t size)
//{
//	void* temp = malloc(size);
//}

//permute takes:
//a pointer to the previous permutation - [prev]
//a pointer to store of the next permutation - [next]
//the size of the sequence to of permutation - [size]
//
//returns a pointer to the start of [next]
//
//assumes proper malloc of prev and next
int	*permute(int *prev, int *next, size_t size)
{
    int *save_lower;
    int *save_upper;

    save_lower = NULL;
    save_upper = NULL;
	size_t k = 0;
	if (size == 0)
		return NULL;
	while(size - k)
	{
		if (((size - 1) - k) && *(prev + k) < *(prev + k + 1))
		{
			save_lower = prev + k;
			save_upper = prev + k + 1;
		}
		else if (save_lower != NULL && *save_lower < *(prev + k))
			save_upper = prev + k;
		*(next + k) = *(prev + k);
		k++;
	}
	if (save_lower != NULL)
	{
		*(next + (save_lower-prev)) = *save_upper;
		*(next + (save_upper-prev)) = *save_lower;
		rev_int_arr(next + (save_lower-prev) + 1, size - (save_lower-prev) - 1);
	}
	return next;
}

// print numbers (char) from int
void ft_putchar(char c)
{
	c = c + 48;
	write(1, &c, 1);
}

void	ft_swap(int *a, int*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	rev_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		ft_swap(&tab[i], &tab[j]);
		i++;
		j--;
	}
}


void    transp_matrix(int arr[4][4])
{
    int r_arr[4][4];
    int j = 0;
    while (j < 4)
    {
        r_arr[0][j] = arr[j][0];
        r_arr[1][j] = arr[j][1];
        r_arr[2][j] = arr[j][2];
        r_arr[3][j] = arr[j][3];
        j++;
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
    || ((ch[i] < ch[i + 1]) && (ch[i + 1] > ch[i + 2]) && (ch[i + 1] > ch[i + 3])))
        return 2;

    if ((ch[i] > ch[i + 1] && ch[i] > ch[i + 2] && ch[i + 2] < ch[i + 3])
    || (ch[i] < ch[i + 1] && ch[i + 1] > ch[i + 2] &&  ch[i + 1] < ch[i + 3])
    || (ch[i] > ch[i + 1] && ch[i + 1] < ch[i + 2] &&  ch[i + 1] < ch[i + 3])
    || (ch[i] < ch[i + 1] && ch[i + 1] < ch[i + 2] &&  ch[i + 2] > ch[i + 3]))
        return 3;

    if (ch[i] < ch[i + 1] && ch[i + 1] < ch[i + 2] && ch[i + 2] < ch[i + 3])
        return 4;
    return -1;
}

void count_row(int arr[4][4])
{
    size_t size = 4;
    int *counts_rl = malloc(size * sizeof(int));
    int *counts_rr = malloc(size * sizeof(int));
    int j = 0;

    // count R-L
    while (j < 4)
    {
        counts_rl[j] = count_view(arr[j]);
        j++;
    }

    // count R-R
    // reverse tab
    int i = 0;
    while (i < 4)
        rev_tab(arr[i++], 4);

    write(1, "\n", 1);

    j = 0;
    while (j < 4)
    {
        counts_rr[j] = count_view(arr[j]);
        j++;
    }
}


// takes 2d array as input, and output array to transpose to
//
// yield a tranposed array
int **transpose_arr(const int arr[4][4], int transp_arr[4][4])
{
    int j = 0;
    while (j < 4)
    {
        transp_arr[0][j] = arr[j][0];
        transp_arr[1][j] = arr[j][1];
        transp_arr[2][j] = arr[j][2];
        transp_arr[3][j] = arr[j][3];
        j++;
    }
    return (transp_arr);
}

int	ft_intcmp(int *s1, int *s2)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (count == 0)
		count += s1[i] - s2[i];
	return (count);
}

void print_matrix(int **arr, size_t rows, size_t cols)
{
	size_t i = 0;
	size_t j = 0;

	while (j < rows)
	{
		i = 0;
		while (i < cols)
		{
			ft_putchar(arr[j][i]);
			if (i < cols - 1)
				write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

void print_tab(int *arr, size_t size)
{
	size_t i = 0;
	while (i < size)
		ft_putchar(arr[i++]);
}

void ft_puterr(char* error_detail)
{
	if (error_detail != NULL)
	{
		char *errormsg = "error:\n";
		write(2, errormsg, ft_strlen(errormsg));
		write(2, error_detail, ft_strlen(error_detail));
	}
	else
	{
		char *errormsg = "error\n";
		write(2, errormsg, ft_strlen(errormsg));
	}
}

//ft_findspc takes a NUL-terminated string - "str"
//returns a pointer to the first space(ASCII 32, ' ') in the string
//otherwise return a NULL
char*	ft_findspc(char* str)
{
	char* res = NULL;
	int i;
	i = 0;
	while (str[i] != '\0')
	{
	 if (str[i] == ' ')
	 {
		 res = &str[i];
	 }
	 i++;
	}
	return res;
}

//ft_countspc takes a NUL-terminated string - "str"
//returns the number of space(ASCII 32, ' ') chars in the string
int	ft_countspc(char* str)
{
	int count = 0 ;
	int i;
	i = 0;
	while (str[i] != '\0')
	{
	  if(str[i] == ' ')
	  {
		  count++;
	  }
	 i++;
	}
	return count;
}

bool check_string(char* str, unsigned int n)
{
	size_t format_spc_count = ft_power(n, 2) - 1;
	size_t format_length = ft_power(n, 2) + format_spc_count;
	size_t i = 0;
	if (ft_strlen(str) == format_length  && ft_countspc(str)  == format_spc_count)
	{
	while(i < format_length)
	{
		if (!(('0' < str[i] && str[i] <= n + 48) || str[i] == ' '))
		{
			return false;
		}
		i++;
	}
	return true;
	}
	else
		return false;
}

bool check_num(int *arr, int n, size_t size)
{
	size_t i;
	i = 0;
	while(i < size)
	{
		if (arr[i] <= 0 || arr[i] > n)
		{
			return false;
		}
		i++;
	}
	return true;
}

// compare results and user-input
// returns 0 if perfect match
// return != 0 when no match
int checker(int input[16], int result[16])
{
    int	i = 0;
    int count = 0;
    while (count == 0 && i < 16)
    {
        count += input[i] - result[i];
        i++;
    }
    return (count);
}

// count nbr of boxes seen from all POV (CU CD RR RL)
// writes results to "results" array in main
void count_rows(int arr[4][4], int *dest_arr)
{
    int i = 0;
    int j = 0;

    size_t size = 4;
    int *result_counter = malloc(size * sizeof(int));

    // create tranposed array with column values to check
    int transp_arr[4][4];
    transpose_arr(arr, transp_arr);

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
        result_counter[k++] = count_view(arr[j++]);

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

bool sudoku(int **matrix, size_t n)
{
	n = 4;
	int i, j = 0;
	int sum = 0;
	while (i < n)
	{
		ft_sort_int_tab(&matrix[i++][j], n);
		if (matrix[i][j] != n)
			return false;
		sum += matrix[j][i];
	}
	
	int transp_matrix[ft_power(n, 2)]; 
	transpose_arr(**matrix, transp_matrix);

	return true;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	while (k == 1)
	{
		i = 0;
		k = 0;
		while (i < size)
		{
			j = i + 1;
			while (j < size)
			{
				if (tab[i] > tab[j])
				{
					ft_swap(&tab[i], &tab[j]);
					k = 1;
				}
				j++;
			}
			i++;
		}
	}
}