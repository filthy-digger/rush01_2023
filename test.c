#include <unistd.h>
#include <stdio.h>

int count_view(int *ch);

void ft_putchar(char c);

int main(void)
{
    int test_arr[4] = {2, 1, 3, 4};

    count_view(test_arr);
    printf("%d", count_view(test_arr));

    return (0);
}