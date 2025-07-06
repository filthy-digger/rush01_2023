/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:38:43 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/21 14:38:44 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "lib_aux.h"

void			ft_putnbr(int nb);

size_t			ft_strlen(char *str);

int				*permute(int *prev, int *next, size_t size);

int				ft_power(int b, unsigned int e);

unsigned int	factorial(unsigned int n);

void			swap_int(int *ptr1, int *ptr2);

int				*rev_int_arr(int *arr, size_t size);

void			ft_putchar(char c);

unsigned int	count_in(const int *arr, size_t size, bool (*pred)(const int, size_t, const int*));

bool	is_visible(int e, size_t i, const int *arr);

unsigned int count_visible(const int *arr, size_t size);

int				**transpose_matrix(int **matrix, int **matrix_transpose,
					size_t rows, size_t cols);

// col1up col2up col3up col4up col1down col2down col3down col4down row1left
// row2left row3left row4left row1right row2right row3right row4right
//"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 1"

// parse_uinput takes:
//"str" - a pointer to a NUL-terminated string
//"n_out" - a pointer to store the calculated square side length
//
// returns an array of unsigned int if successful, NULL otherwise
//
// format is:
// String of integers separated by spaces, where total count is divisible by 4
// Each integer must be in range [1, n] where n = total_count/4
unsigned int * parse_uinput(char *str, unsigned int *n_out);

void			print_matrix(int **arr, size_t rows, size_t cols);

void			puterr(char *error_detail);

bool checker(const unsigned int *input, const unsigned int *result, size_t size);

void			count_rows(int **matrix, unsigned int *dest_arr, size_t size);

bool			sudoku(int **matrix, size_t n);

int				**gen_permutations(size_t size);

int				**malloc_matrix(size_t cols, size_t rows);

int				**malloc_matrix_rows(size_t rows);

int				**gen_solution(size_t size, unsigned int *input);

// Optimized functions
bool			sudoku_columns(int **matrix, size_t n);
bool			sudoku_complete(int **matrix, size_t n);
void			count_rows_optimized(int **matrix, unsigned int *dest_arr, size_t size);
int				**gen_solution_recursive_optimized(size_t size, unsigned int *input,
					int **permutation_matrix, int **solution_matrix, unsigned int *views,
					size_t permutations, int current_row);
bool			sudoku_columns_partial(int **matrix, size_t n, int filled_rows);
int				**gen_solution_optimized(size_t size, unsigned int *input);

#endif // LIB_H
