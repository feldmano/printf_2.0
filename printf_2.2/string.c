/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:23:05 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 15:18:03 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // for ssize_t, size_t
#include "include/memory/memory.h" // for free, pf_calloc, pf_strjoin
#include "include/math/math.h" // for digitcounters

char	*utoa(unsigned int unsig)
{
	unsigned int	len;
	char			*str;

	len = size_digitcounter((size_t)unsig);
	str = pf_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = unsig % 10 + '0';
		unsig /= 10;
	}
	return (str);
}

char	*itoa(int n)
{
	char	*str;
	char	*cpy;
	size_t	digit;

	if (n == -2147483648)
		return (pf_strjoin("-", "2147483648"));
	if (n < 0)
	{
		cpy = itoa(-n);
		if (!cpy)
			return (NULL);
		str = pf_strjoin("-", cpy);
		return (free (cpy), str);
	}
	digit = llong_digitcounter(n);
	str = pf_calloc(digit + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[digit] = '\0';
	while (digit != 0)
	{
		str[--digit] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}

char	*pf_strchr(const char *str, const char c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		++str;
	}
	return (NULL);
}

ssize_t	pf_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
