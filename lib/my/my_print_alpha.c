#include "my.h"

int	my_print_alpha(void)
{
	int	i = 97;

	while (i != 123) {
		my_putchar(i);
		i++;
	}
	return (0);
}
