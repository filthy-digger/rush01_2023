#include "lib.h"

int main(void)
{
	size_t	size = 4;
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
		if (i == 0) for(size_t j = 0; j<cols; j++)
			matrix[i][j] = j+1;
		else
			permute(matrix[i-1], matrix[i], cols);
	}

	//int*	perm_1 = malloc(size * sizeof(int));
	//int	output[] = permute(perm_0, perm_1, size);
	//printf("%d\n", *output);

	return 0;
}
