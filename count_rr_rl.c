#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void rev_tab(int *tab, int size);


// print numbers (char) from int
void ft_putchar(char c)
{
    c = c + 48;
    write(1, &c, 1);
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
    || (ch[i] < ch[i + 1] && ch[i + 1] < ch[i + 2] &&  ch[i + 2] > ch[i + 3]))
        return 3;

    if (ch[i] < ch[i + 1] && ch[i + 1] < ch[i + 2] && ch[i + 2] < ch[i + 3])
        return 4;
    return -1;
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

// print 1d tab for testing purpose
void print_tab(int arr[16])
{
    int i = 0;
    while (i < 4)
            ft_putchar(arr[i++]);
}



void count_rows(int arr[4][4])
{
    int i = 0;
    int j = 0;
    int counts_rl[4] = {}; 
    int counts_rr[4] = {}; 
    int counts_cu[4] = {}; 

    
    // FUNCTION
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

    i = 0; 
    j = 0;
    // count C-U
    while (i < 4)
    {
        while (j < 4)
        {
            counts_cu[j] = count_view(&arr[i][j]);
            j++;
        }
        i++;
    }





    // PRINTING FOR TESTING 
    print_tab(counts_rl);
    write(1, "\n", 1);
    print_tab(counts_rr);
    write(1, "\n", 1);
    print_tab(counts_cu);
}





// params in main
int main(void)
{
    int arr[4][4] = {{4, 3, 2, 1}, {2, 4, 1, 3}, {3, 1, 4, 2}, {1, 2, 3, 4}};

    print_matrix(arr);

    count_rows(arr);

    return (0);
}