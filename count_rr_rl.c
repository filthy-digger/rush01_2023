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



// count nbr of boxes seen from all POV (WIP for CU and CD)
void count_rows(int arr[4][4])
{
    int i = 0;
    int j = 0;

    // create array to store results
    size_t size = 4;
    int *result_counter = malloc(size * sizeof(int));

    // FUNCTION
    // create tranposed array with column values to check
    int transp_arr[4][4];
    j = 0;
    while (j < 4)
    {
        transp_arr[0][j] = arr[j][0];
        transp_arr[1][j] = arr[j][1];
        transp_arr[2][j] = arr[j][2];
        transp_arr[3][j] = arr[j][3];
        j++;
    }

    // count C-U
    j = 0;
    while (j < 4)
    {
        result_counter[j] = count_view(transp_arr[j]);
        j++;
    }
    

    printf("transp arr : \n");
    print_matrix(transp_arr);

    // count C-D
    // reverse tab
    while (i < 4)
        rev_tab(transp_arr[i++], 4);

    printf("transp rev arr : \n");
    print_matrix(transp_arr);

    printf("arr : \n");
    print_matrix(arr);

    j = 0;
    while (j < 8)
    {
        result_counter[j + 4] = count_view(transp_arr[j]);
        j++;
    }
    

    // count R-L
    j = 0;
    while (j < 12)
    {
        result_counter[j + 8] = count_view(arr[j]);
        j++;
    }

    // count R-R
    // reverse tab
    i = 0;
    while (i < 4)
        rev_tab(arr[i++], 4);


     printf("rev arr : \n");
    print_matrix(arr);


    j = 0;
    while (j < 16)
    {
        result_counter[j + 12] = count_view(arr[j]);
        j++;
    }

    

     //       counts_cu[j] = count_view(&arr[i][j]);

    // PRINTING FOR TESTING 
   print_tab(result_counter);
   write(1, "\n", 1);
 //  print_tab(counts_cd);


}





// params in main
int main(void)
{
    int arr[4][4] = {{1, 2, 3, 4}, {2, 1, 4 ,3}, {4, 3, 1, 2}, {3, 4, 2, 1}};

    count_rows(arr);

    return (0);
}