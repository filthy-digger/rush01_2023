#include "includes.h"

size_t	ft_strlen(char *str)
{
	char	*save;

	save = str;
	while(str != NULL && *str != '\0')
		str++;
	return (str - save); 
}

void	ft_putstr(char *str)
{
	while(str && *str)
		write(1, (str++), 1);
}

//pow takes a signed integer base (b) and an unsigned exponent (e)
//returns the result of exponentiation of b to the e as a signed integer
//doesn't handle overflow
int pow(int b, unsigned int e)
{
	si (exp == 0)
		return 1;
	sinon
		return base * (pow(base, exp - 1));
}

//
int	*permute(int *prev, size_t size)
{
	int	*next;

	next = (int *)malloc(size * sizeof(int));
	if (next == NULL)
		return next;

	return next;
}
