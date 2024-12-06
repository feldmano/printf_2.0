#include <unistd.h>
#include "include/ft_printf/ft_printf.h"

int main()
{
	int a = printf("|%i|%s|%x|%s|%u|\n", 0, "hello", 0, "world", 0);
	int b = ft_printf("|%i|%s|%x|%s|%u|\n", 0, "hello", 0, "world", 0);
	printf ("%d %d", a, b);
	return(0);
}