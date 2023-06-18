/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:15:33 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/18 18:10:55 by lfick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdbool.h>


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

void ft_puterr(char* error_detail)
{
	if (error_detail != NULL)
	{
		char *errormsg = "error:\n";
		write(2, errormsg, ft_strlen(errormsg));
		write(2, error_detail, ft_strlen(error_detail));
	}
	else
	{
		char *errormsg = "error\n";
		write(2, errormsg, ft_strlen(errormsg));
	}
}

//col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right

//ft_findspc takes a NUL-terminated string - "str"
//returns a pointer to the first space(ASCII 32, ' ') in the string
//otherwise return a NULL
char*	ft_findspc(char* str)
{
	char* res = NULL;
	int i;
	i = 0;
	while (str[i] != '\0')
	{
	 if (str[i] == ' ')
	 {
		 res = &str[i];
	 }
	 i++;
	}
	return res;
}

//ft_countspc takes a NUL-terminated string - "str"
//returns the number of space(ASCII 32, ' ') chars in the string
int	ft_countspc(char* str)
{
	int count = 0 ;
	int i;
	i = 0; 
	while (str[i] != '\0')
	{
	  if(str[i] == ' ')
	  {
		  count++;
	  }
	 i++;
	}
	return count;
}

//check_string takes a pointer to a NUL-terminated string - "str"
//
//returns a boolean:
//true if the string follows the ruhs01 format
//false otherwise
//
//format is:
//length is 31
//space count is 15
bool check_string(char* str)
{
	size_t format_len = 31;
	int format_spc_count = 15;
	if (ft_strlen(str) == 31 && ft_countspc(str)  == 15)
		return true;
	else
		return false;
}
//"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"	
int main(int argc, char **argv)
{
	if (argc != 2)
    {
        ft_puterr(NULL);
        return 1;
    }
	if (check_string(argv[1]))
	{
		ft_putstr("ok format\n");
		return 0;
	}
	else
    {
        ft_puterr("bad format");
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
