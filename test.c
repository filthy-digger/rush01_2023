/*     j = 0;
    int k = 0;
    while (j < 4)
        result_counter[k++] = count_view(transp_arr[j++]);

    j = 0;
    while (j < 4)
    {
        rev_tab(transp_arr[j], 4);
        result_counter[k++] = count_view(transp_arr[j++]);
    }

    j = 0;
    while (j < 4)
        result_counter[k++] = count_view(arr[j++]);

    j = 0;
    while (j < 4)
    {
        rev_tab(arr[j], 4);
        result_counter[k++] = count_view(arr[j++]);
    }

 */
#include "lib.h"
int count_view(int *ch);

int main(void)
{
    int arr[] = {1, 4, 3, 2,};
   
    printf("%d", count_view(arr));
}