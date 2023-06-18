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

int    transp_matrix(arr[4][4])
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



void count_row(int arr[4][4])
{
    int counts_rl[4] = {}; 
    int counts_rr[4] = {}; 
    int j = 0;

    // count R-L
    while (j < 4)
    {
        counts_rl[j] = count_view(arr[j]);
        j++;
    }

    // count R-R
    // reverse tab
    i = 0;
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

/* void    count_col(int arr[4][4])
{
         
} */

