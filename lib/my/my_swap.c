#include "my.h"

int	my_swap(int *a, int *b)
{
	int	i = *a;

	*a = *b;
	*b = i;
	return (0);
}
