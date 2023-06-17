#include <stdio.h>
#include <stdlib.h>


// calculates visible boxes for view
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

void print_tab(int **arr)
{
    int i = 0;
    while (i < 4)
    {
        int j = 0;
        while (j < 4)
        {
            putchar(arr[i][j]);
            j++;
        }
        i++;
    }
}

    

// params in main
int main(void)
{
    int r1[4] = {1, 2, 3, 4};
    int r2[4] = {2, 1, 4, 3};
    int r3[4] = {3, 4, 1, 2};
    int r4[4] = {4, 3, 2, 1};

    int *ar[4] = {r1, r2, r3, r4};

    int arr[4][4] = { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4} };

//    printf("%d\n\n", arr[3][3]);
        
//    printf("%d\n", count_view(*ar));

    print_tab(arr);

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
