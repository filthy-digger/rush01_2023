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
    || (ch[i] < ch[i + 1] && ch[i + 1] < ch[i + 2] &&  ch[i + 2] > ch[i + 3]))
        return 3;

    if (ch[i] < ch[i + 1] && ch[i + 1] < ch[i + 2] && ch[i + 2] < ch[i + 3])
        return 4;
    return -1;
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

// print 1d tab for testing purpose
void print_tab(int arr[16])
{
    int i = 0;
    while (i < 4)
            ft_putchar(arr[i++]);
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






// params in main
int main(void)
{
    // int r1[4] = {1, 2, 3, 4};
    // int r2[4] = {1, 2, 3, 4};
    // int r3[4] = {1, 2, 3, 4};
    // int r4[4] = {1, 2, 3, 4};

    // int arr[4] = {r1, r2, r3, r4};

    int arr[4][4] = {{4, 3, 2, 1}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

    print_matrix(arr);

    printf("\n%d\n", count_rows(arr));

//    count_view()

    return (0);
}










// params as args
/* int main(int argc, char **argv)
{
    int i = 0;
    int chain[4];

    while (i < 4)
    {
        chain[i] = atoi(argv[i + 1]);
        i++;
    }
        
    printf("%d\n", count_view(chain));

    return (0);
} */
