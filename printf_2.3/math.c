/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 20:16:24 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/23 13:36:19 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t

int	llong_digitcounter(long long int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		++len;
		num /= 10;
	}
	return (len);
}

int	size_digitcounter(size_t size)
{
	int	len;

	len = 0;
	if (size == 0)
		return (1);
	while (size > 0)
	{
		++len;
		size /= 10;
	}
	return (len);
}
