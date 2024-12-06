/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 20:46:47 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/23 13:37:43 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // for malloc
#include <stddef.h> // for size_t

void	*pf_calloc(size_t mems, size_t size)
{
	void	*ptr;
	size_t	len;

	len = mems * size;
	if (size != 0 && len / size != mems)
		return (NULL);
	ptr = malloc (len);
	if (!ptr)
		return (NULL);
	while (len > 0)
		((unsigned char *)ptr)[--len] = 0;
	return (ptr);
}
