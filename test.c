#include "src/printf.h"
#include <stdio.h>
#include <limits.h>
#include <math.h>

int main()
{
	double f = INFINITY;
	double mf = -INFINITY;
	double nf = f - f;
	printf("%f %f %f %s\n", f, mf, nf, "test");
	ft_printf("%f %f %f %s\n", f, mf, nf, "Test");
}