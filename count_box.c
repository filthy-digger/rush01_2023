#include <stdio.h>
#include <stdlib.h>

int count_vue(int *ch)
{
    int i = 0;
    int count = 0;

    if (ch[i] == 4)
        count = 1;

    if (((ch[i] > ch[i + 1])    && (ch[i] < ch[i + 2])      &&  (ch[i + 2] > ch[i + 3])) 
    || ((ch[i] > ch[i + 1])     &&  (ch[i] > ch[i + 2])     &&  (ch[i + 1] < ch[i + 3])) 
    || ((ch[i] < ch[i + 1])     &&  (ch[i + 1] > ch[i + 2]) &&  (ch[i + 2] > ch[i + 3])))
        count = 2;

    if ((ch[i] > ch[i + 1]      &&  ch[i + 1] > ch[i + 2]   &&  ch[i + 1] < ch[i + 3]) 
    || (ch[i] < ch[i + 1]       &&  ch[i + 1] > ch[i + 2]   &&  ch[i] < ch[i + 3]) 
    || (ch[i] < ch[i + 1]       &&  ch[i + 1] < ch[i + 2]       &&  ch[i + 1] > ch[i + 3]))
        count = 3;

    if (ch[i] < ch[i + 1] && ch[i + 1] < ch[i + 2] && ch[i + 2] < ch[i + 3])
        count = 4;

    return count;
}

int main(int argc, char **argv)
{
    int i = 0;
    int chain[4];

    while (i < 4)\
    {
        chain[i] = atoi(argv[i + 1]);
        i++;
    }
    

//  int chain[4] = {4, 3, 2, 1};
    
    printf("%d\n", count_vue(chain));

    return (0);
}