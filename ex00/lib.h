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

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void			ft_putnbr(int nb);

size_t			ft_strlen(char *str);

int				*permute(int *prev, int *next, size_t size);

int				ft_power(int b, unsigned int e);

unsigned int	factorial(unsigned int n);

void			swap_int(int *ptr1, int *ptr2);

int				*rev_int_arr(int *arr, size_t size);

void			ft_putchar(char c);

int				count_view(const int *ch);

int				**transpose_matrix(int **matrix, int **matrix_transpose,
					size_t rows, size_t cols);

// col1up col2up col3up col4up col1down col2down col3down col4down row1left
// row2left row3left row4left row1right row2right row3right row4right
//"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 1"

// parse_uinput takes:
//"str" - a pointer to a NUL-terminated string
//"n" - square side length
//
// returns a boolean:
// true if the string follows the rush01 format
// false otherwise
//
// format is:
//"space_count" = n^2 - 1
// length =  n^2  + "space_count"
int				*parse_uinput(char *str, unsigned int n);

void			print_matrix(int **arr, size_t rows, size_t cols);

void			puterr(char *error_detail);

int				checker(const int *input, const int *result, size_t size);

void			count_rows(int **matrix, int *dest_arr, size_t size);

bool			sudoku(int **matrix, size_t n);

int				**gen_permutations(size_t size);

int				**malloc_matrix(size_t cols, size_t rows);

int				**malloc_matrix_rows(size_t rows);

int				**gen_solution(size_t size, int *input);

#endif // LIB_H
