#include "lib.h"

// imports


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

int main(void)
{
    int arr[4][4] = {{1, 2, 3, 4}, {2, 1, 4 ,3}, {4, 3, 1, 2}, {3, 4, 2, 1}};  // sample matrix
    int u_input[16] = {3, 3, 2, 1, 2, 1, 2, 4, 4, 2, 1, 2, 1, 2, 3, 3}; // sample user input
    int results[16] = {9, 3, 2, 1, 2, 1, 2, 4, 4, 4, 1, 2, 3, 2, 3, 3}; // empty array to store results



    count_rows(arr, results);


    printf("%d", checker(u_input, results));




/*     for (int i = 0; i < 16; i++)
        printf("%d", results[i]);
 */
 //   checker()

    return (0);
}