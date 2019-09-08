#include "src/printf.h"

int main()
{
	ft_printf("{% 03d}\n", 0);
	printf("{% 03d}\n", 0);

	ft_printf("{%+03d}\n", 0);
	printf("{%+03d}\n", 0);
	return (0);
}