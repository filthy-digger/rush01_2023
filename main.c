/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:15:33 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/17 23:34:08 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void ft_putchar(char c)
{
	c = c + 48;
	write(1, &c, 1);
}

void print_matrix(int **arr, size_t rows, size_t cols)
{
	size_t i = 0;
	size_t j = 0;

	while (j < rows)
	{
		i = 0;
		while (i < cols)
		{
			ft_putchar(arr[j][i]);
			if (i < cols - 1)
				write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}
void print_tab(int *arr, size_t size)
{
	size_t i = 0;
	while (i < size)
		ft_putchar(arr[i++]);
}


int main(int argc, char **argv)
{
	if (argc != 2)
    {
        char *str = "error\n";
        write(2, str, ft_strlen(str));
        return 1;
    }
	size_t	size = (size_t)(argv[1][0] - 48);
	size_t	cols = size;
	size_t	rows = factorial(size);
	int**	matrix = (int**)malloc(rows * sizeof(int*));
	if (matrix == NULL)
		return 1;
	for(size_t i = 0; i < rows; i++)
	{
		matrix[i] = (int *)malloc(cols * sizeof(int));
		if (matrix[i] == NULL)
			return 1;
		if (i == 0) 
			for(size_t j = 0; j<cols; j++)
				matrix[i][j] = j+1;
		else
			permute(matrix[i-1], matrix[i], cols);
	}
	print_matrix(matrix, rows, cols);

	//int*	perm_1 = malloc(size * sizeof(int));
	//for(size_t j = 0; j<size; j++)
	//	*(perm_1+j) = j+1;
	//rev_int_arr(perm_1, size);
	//print_tab(perm_1, size);
	////int	output[] = permute(perm_0, perm_1, size);
	//printf("%d\n", *output);

	return 0;
}
