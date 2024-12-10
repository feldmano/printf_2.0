#include "printf/ft_printf.h"
#include <stdio.h>

int main()
{
	int z = printf("str[%.3s]\n", "hello");
	int w = printf("str[%.0s]\n", "hello");
	printf("%d %d\n",z, w);


	int a = ft_printf("[%+03i]\n", 23);
	int b = printf("[%+03i]\n", 23 );
	printf("%d %d\n",a, b);
	
	
	return (0);
}