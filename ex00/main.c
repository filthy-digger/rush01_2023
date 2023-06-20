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

	size = 4;
	if (argc == 3)
	{
		size = (size_t) (argv[2][0] - 48);
		int **permutation_matrix = gen_permutations(size);
		print_matrix(permutation_matrix, factorial(size), size);
		return 0;
	}

	if (argc != 2)
	{
		puterr(NULL);
		return 1;
	}
	int* uinput = parse_uinput(argv[1], size);
	if (uinput == NULL)
	{
		puterr("bad format\n");
		return 1;
	}
//	print_arr(uinput, ft_power((int) size, 2));

	int **solution = gen_solution(size, uinput);
	if (solution == NULL)
	{
		puterr("no solution");
		return  1;
	}
	else
	{
		print_matrix(solution, size, size);
	}
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
	transpose_matrix(matrix, matrix_transpose);*/

 /*   if (!(sudoku_alt(matrix, size) && (sudoku_alt(matrix_transpose, size)))) {
		if (!(sudoku_alt(matrix, size)))
			ft_puterr("bad sudoku\n");
		if (!(sudoku_alt(matrix_transpose, size)))
			puterr("bad sudoku transpose\n");
		return 1;
	}*/
	int u_input[16] = {1, 1, 1, 1,
					   1,1, 1, 1,
					   1, 1,1, 1,
					   1, 1, 1, 1}; // sample user input

//    return 0;
	int results[16] = {9, 3, 2, 1, 2, 1, 2, 4, 4, 4, 1, 2, 3, 2, 3, 3}; // empty array to store results



	count_rows(solution, results);


	printf("%d", checker(u_input, results));

	return 0;

	//int*	perm_1 = malloc(size * sizeof(int));
	//for(size_t j = 0; j<size; j++)
	//	*(perm_1+j) = j+1;
	//rev_int_arr(perm_1, size);
	//print_arr(perm_1, size);
	////int	output[] = permute(perm_0, perm_1, size);
	//printf("%d\n", *output);

	return 0;
}
