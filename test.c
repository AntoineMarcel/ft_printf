#include "src/printf.h"
#include <stdio.h>
int main()
{
ft_printf("@main_ftprintf: %33..1..#0d\\n     \n", 256);
printf("@main_ftprintf: %33..1..#0d\\n", 256);
}