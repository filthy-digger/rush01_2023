#include "includes.h"

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
	for(size_t i = size/2; i < 0 ;  i--)
		swap_int(arr+(size-1)-i,arr+i);
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
	int* save_lower = NULL;
	int* save_upper = NULL;
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
		(next + (save_upper-prev))
	}

	return next;
}
