#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// imports
void rev_tab(int *tab, int size);
void count_row(int arr[4][4]);
void ft_putchar(char c);
int count_view(int *ch);
void print_tab(int arr[16]);
void print_matrix(int arr[4][4]);
int transpose_arr(int arr[4][4], int transp_arr[4][4]);


// count nbr of boxes seen from all POV (WIP for CU and CD)
void count_rows(int arr[4][4])
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

   print_tab(result_counter);
   write(1, "\n", 1);
}





// params in main
int main(void)
{
    int arr[4][4] = {{1, 2, 3, 4}, {2, 1, 4 ,3}, {4, 3, 1, 2}, {3, 4, 2, 1}};

    count_rows(arr);

    return (0);
}