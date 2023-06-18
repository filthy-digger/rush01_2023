#include "lib2.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "includes.h"

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

// display solution table
//
// only handle 4x4 table
void print_matrix(int arr[4][4])
{
    int i = 0;
    int j = 0;

    while (j < 4)
    {
        i = 0;
        while (i < 4)
        {
            ft_putchar(arr[j][i]);
            if (i < 3)
                write(1, " ", 1);
            i++;
        }
        write(1, "\n", 1);
        j++;
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

// print 1d tab for testing purpose
void print_tab(int arr[16])
{
    int i = 0;
    while (i < 16)
        ft_putchar(arr[i++]);
}

/* void    count_col(int arr[4][4])
{
         
} */

// takes 2d array as input, and output array to transpose to
//
// yield a tranposed array
int *transpose_arr(const int arr[4][4], int transp_arr[4][4])
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
    return (*transp_arr);
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

int count_rows(int arr[4][4])
{
    int i = 0;
    int j = 0;
    int counts_rl[16] = {};

    // count R-L
    while (j < 4)
    {
        counts_rl[i] = count_view(arr[i++]);
        j++;
    }
    int k = 0;
     while (k < 4)
        printf("%d", &arr[k++]);


    // count R-R
    int r_arr[4];
    k = 0;

    *r_arr = rev_tab(arr, 4);

    k = 0;
    while (k < 4)
    {
        r_arr[k] = arr[k];
        k++;
    }
    k = 0;
    while (k < 4)
        printf("%d", r_arr[i++]);
    k = 0;
    printf("   ");


    while (j < 4)
    {
        counts_rr[i] = count_view(r_arr[i++]);
        j++;
    }




    print_tab(counts_rl);
    write(1, " ", 1);
    print_tab(counts_rl);

    return (*counts_rl);
}