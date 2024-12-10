/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_mixed.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 11:41:06 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/10 15:35:48 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <stdio.h>

int main()
{

int num = 42;
void *ptr = &num;

int bs  = ft_printf("mixed [%#X][%p][%p][%s][%3#0X][%30#0X][%p]\n", -15, ptr, NULL, "hello", -24 -42, &ptr);
printf("\n");
int bd = printf("mixed [%#X][%p][%p][%s][%3#0X][%30#0X][%p]\n", -15, ptr, NULL, "hello", -24, -42, &ptr);
printf("%d %d\n",bs, bd);
}
