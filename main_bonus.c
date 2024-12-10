#include "printf/ft_printf.h"
#include <stdio.h>

int main()
{

	int e = ft_printf(NULL);
	int f =    printf(NULL);
	printf("\nNULL\n");


	int g = ft_printf("");
	int h =    printf("");
	printf("\nDBL_QT\n");
	
	int k = ft_printf("isolated_percents:% % %");
	int l =    printf("isolated_percents% % %");
	printf("\n%d %d\n", k, l);
	
	int z =ft_printf("percent_newline%0\n");
	int w = printf("percent_newline%0\n");
	printf("%d %d\n",z, w);


	int n = ft_printf("negative int for char[%c]\n", -1);
	int m =    printf("negative int for char[%c]\n", -1);
	printf("\n%d %d\n", n, m);


	int a = ft_printf("no_specifier[%03%u]\n", 23);
	int b = printf("no_specifier[%03%u]\n", 23 );
	printf("%d %d\n",a, b);
	

	int x = ft_printf("[no_specifier with_string |%07%u%0%s]\n", 23, "helllo");
	int y =    printf("[no_specifier with_string |%07%u%0 %s]\n", 23, "hello" );
	printf("%d %d\n",x, y);
	
	
	int r = ft_printf("padding with unsigned[%0007u]\n", 234);
	int s = printf("padding with unsigned[%0007u]\n", 234);
	printf("\n%d %d\n", r, s);


	int t = ft_printf("left justice with unsigned[%000-7u]\n", 234);
	int u =    printf("left justice with unsigned[%000-7u]\n", 234);
	printf("\n%d %d\n", t, u);
	
	int c = ft_printf("mixed flags unsinged[%0-03u]\n", 23);
	int d =    printf("mixed flags unsigned[%0-03u]\n", 23);
	printf("%d %d\n",c, d);


	int i = ft_printf("padding with hex[%0004X]\n", 234);
	int j =    printf("padding with hex[%0004X]\n", 234);
	printf("%d %d\n", i, j);


	int o = ft_printf("int[%+04i][%+04i][%-03i][%-03i]\n", 23, 23, 23, -42);
	int v =    printf("int[%+04i][%+04i][%-03i][%-03i]\n", 23, 23, 23, -42);
	printf("%d %d\n",o, v);
	

	int p = ft_printf("mixed flags int[%0 -0-4i][%0+05i][%0+05i][%0+0i]\n", 23, 24, -42, -42);
	int q =    printf("mixed flags int[%0 -0-4i][%0+05i][%0+05i][%0+0i]\n", 23, 24, -42, -42);
	printf("%d %d\n",p, q);;
	

	int bs  = ft_printf("mixed [%0 -0-4p][%0+05x][%0+05p][%0+0X]\n", NULL, -24, &p, -42);
	printf("\n");
	int bd=    printf("mixed [%0 -0-4p][%0+05x][%0+05p][%0+0X]\n", NULL, -24, &p, -42);
	printf("%d %d\n",bs, bd);;
	
	

	return (0);
}