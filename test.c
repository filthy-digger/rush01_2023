#include <unistd.h>

void ft_putchar(char c)
{
    c = c + 48;
    write(1, &c, 1);
}

int main(void)
{
    int arr[4][4] = { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4} };

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

    return (0);
}