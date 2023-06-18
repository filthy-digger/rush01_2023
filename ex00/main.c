/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:15:33 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/18 19:47:20 by lfick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

//col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right

//check_string takes:
//"str" - a pointer to a NUL-terminated string
//"n" - square side length
//
//returns a boolean:
//true if the string follows the rush01 format
//false otherwise
//
//format is:
//"space_count" = n^2 - 1
//length =  n^2  + "space_count"
//check_num takes "arr" - array of integers of length "size"
//checks for bounds of entries of "arr" to be:
//arr[i] > 0
//arr[i] <= n

//"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 1"
int main(int argc, char **argv)
{
    size_t size;

    size = 4;
    if (argc == 3) {
        size = (size_t) (argv[2][0] - 48);
    }
    int **permutation_matrix = gen_permutations(size);
    //print_matrix(permutation_matrix, factorial(size), size);


    int okarr[16] = {1, 2, 3, 4, 2, 1, 4 ,3, 4, 3, 1, 2, 3, 4, 2, 1};
    int badarr[16] = {0, 2, 3, 4, 2, 1, 4 ,3, 4, 3, 1, 2, 3, 5, 2, 0};
    int *testarr = okarr;
    if (argc != 2)
    {
        ft_puterr(NULL);
        return 1;
    }
    if (!check_string(argv[1], 4))
    {
        ft_puterr("bad format\n");
        return 1;
    }
    int arr[4][4] = {{1, 2, 3, 4}, {2, 1, 4 ,3}, {4, 3, 1, 2}, {3, 4, 2, 1}};  // sample matrix
    int u_input[16] = {3, 3, 2, 1, 2, 1, 2, 4, 4, 2, 1, 2, 1, 2, 3, 3}; // sample user input
    int results[16] = {9, 3, 2, 1, 2, 1, 2, 4, 4, 4, 1, 2, 3, 2, 3, 3}; // empty array to store results



    count_rows(arr, results);


    printf("%d", checker(u_input, results));

    return 0;

	//int*	perm_1 = malloc(size * sizeof(int));
	//for(size_t j = 0; j<size; j++)
	//	*(perm_1+j) = j+1;
	//rev_int_arr(perm_1, size);
	//print_tab(perm_1, size);
	////int	output[] = permute(perm_0, perm_1, size);
	//printf("%d\n", *output);

	return 0;
}
