#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// import
void rev_tab(int *tab, int size);
void count_row(int arr[4][4]);


// print numbers (char) from int
void ft_putchar(char c)
{
    c = c + 48;
    write(1, &c, 1);
}

// count visible boxes logic for a row
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

// print 4x4 matrix


// print 1d tab for testing purpose
void print_tab(int arr[16])
{
    int i = 0;
    while (i < 4)
            ft_putchar(arr[i++]);
}


// count nbr of boxes seen from all POV (WIP for CU and CD)
void count_rows(int arr[4][4])
{
    int i = 0;
    int j = 0;
    // create array to store results
    int counts_rl[4] = {}; 
    int counts_rr[4] = {}; 
    int counts_cu[4] = {}; 
    int counts_cd[4] = {}; 


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
    while (j < 4)
    {
        counts_cu[j] = count_view(transp_arr[j]);
        j++;
    }
    // count C-D
    // reverse tab
    i = 0;
    while (i < 4)
        rev_tab(transp_arr[i++], 4);

    write(1, "\n", 1);

    j = 0;
    while (j < 4)
    {
        counts_cd[j] = count_view(transp_arr[j]);
        j++;
    }
    

    count_row(arr[4][4]);
    

     //       counts_cu[j] = count_view(&arr[i][j]);

    // PRINTING FOR TESTING 
   print_tab(counts_rl);
   write(1, "\n", 1);
   print_tab(counts_rr);
   write(1, "\n", 1);
   print_tab(counts_cu);
    write(1, "\n", 1);
 //  print_tab(counts_cd);


}





// params in main
int main(void)
{
    int arr[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

    count_rows(arr);

    return (0);
}