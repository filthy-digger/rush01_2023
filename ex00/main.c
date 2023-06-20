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


int	main(int argc, char **argv)
{
    size_t	size;

    size = 9;
    if (argc == 3)
	{
		size = (size_t) (argv[2][0] - 48);
		int **permutation_matrix = gen_permutations(size);
		print_matrix(permutation_matrix, factorial(size), size);
		return 0;
	}


    int okarr[16] = {1, 2, 3, 4, 2, 1, 4 ,3, 4, 3, 1, 2, 3, 4, 2, 1};
    int badarr[16] = {0, 2, 3, 4, 2, 1, 4 ,3, 4, 3, 1, 2, 3, 5, 2, 0};
    int *testarr = okarr;
    if (argc != 2)
    {
        ft_puterr(NULL);
        return 1;
    }
	int* uinput = check_string(argv[1], 4);
    if (uinput == NULL)
    {
        ft_puterr("bad format\n");
        return 1;
    }
	print_tab(uinput, ft_power(4, 2));
	return 0;

    /*int arr[4][4] = {{1, 2, 3, 4},
                     {2, 1, 4, 3},
                     {4, 3, 1, 2},
                     {3, 4, 2, 1}};  // sample matrix
    int **matrix = malloc_matrix(size, size);
    int **matrix_transpose = malloc_matrix(size, size);
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3; matrix[0][3] = 4;
    matrix[1][0] = 2; matrix[1][1] = 3; matrix[1][2] = 4; matrix[1][3] = 1;
    matrix[2][0] = 4; matrix[2][1] = 2; matrix[2][2] = 1; matrix[2][3] = 3;
    matrix[3][0] = 3; matrix[3][1] = 4; matrix[3][2] = 2; matrix[3][3] = 1;
    transpose_arr(matrix, matrix_transpose);*/

 /*   if (!(sudoku_alt(matrix, size) && (sudoku_alt(matrix_transpose, size)))) {
        if (!(sudoku_alt(matrix, size)))
            ft_puterr("bad sudoku\n");
        if (!(sudoku_alt(matrix_transpose, size)))
            ft_puterr("bad sudoku transpose\n");
        return 1;
    }*/
    int u_input[16] = {1, 1, 1, 1,
                       1,1, 1, 1,
                       1, 1,1, 1,
                       1, 1, 1, 1}; // sample user input
    int **solution = gen_solution(size, u_input);
    if (solution == NULL)
    {
        ft_puterr("no solution");
        return  1;
    }
    else
    {
        print_matrix(solution, size, size);
    }

//    return 0;
    int results[16] = {9, 3, 2, 1, 2, 1, 2, 4, 4, 4, 1, 2, 3, 2, 3, 3}; // empty array to store results



    count_rows(solution, results);


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
