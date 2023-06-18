#include "lib.h"




int count_view(int *ch);

int main(void)
{
    int arr[] = {1, 4, 3, 2,};
    int input[16] = {1, 2, 3, 4, 2, 3, 3, 4, 3, 2, 2, 2, 2, 1, 1, 2}
    printf("%d", count_view(arr));
}