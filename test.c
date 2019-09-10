#include "src/printf.h"
#include <stdio.h>
int main()
{
ft_printf("@main_ftprintf: %33..1..#0x\\n     \n", 256);
printf("@main_ftprintf: %33..1..#0x\\n", 256);
}