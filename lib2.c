#include "includes.h"

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
