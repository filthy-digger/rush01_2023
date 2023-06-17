#include "lib.h"

int main(void)
{
	size_t size = 4;
	int	*inititial_perm = malloc(size * sizeof(int));
	if (inititial_perm == NULL)
		return 1;
	for(size_t i = 0; i<size; i++)
		inititial_perm[i] = i+1;

	return 0;
}
