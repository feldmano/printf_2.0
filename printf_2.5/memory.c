/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 20:46:47 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/03 12:33:09 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // for malloc, free

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

char	*pf_strjoin(const char *str, const char *str2)
{
	char	*join;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	while (str[len1])
		++len1;
	while (str2[len2])
		++len2;
	join = pf_calloc(len1 + len2 + 1, sizeof(char));
	if (!join)
		return (NULL);
	len1 = -1;
	len2 = -1;
	while (str[++len1])
		join[len1] = str[len1];
	while (str2[++len2])
		join[len1 + len2] = str2[len2];
	join[len1 + len2] = '\0';
	return (join);
}
