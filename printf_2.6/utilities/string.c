/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:23:05 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/10 13:03:55 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // for ssize_t, size_t
#include "printf/ft_printf.h" // for enum
#include "memory/memory.h" // for free, pf_calloc, pf_strjoin
#include "math/math.h" // for digitcounters

char	*pf_utoa(unsigned int unsign)
{
	unsigned int	len;
	char			*str;

	len = size_digitcounter((size_t)unsign);
	str = pf_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = unsign % 10 + '0';
		unsign /= 10;
	}
	return (str);
}

char	*pf_itoa(int sign)
{
	char	*str;
	char	*cpy;
	size_t	digit;

	if (sign == -2147483648)
		return (pf_strjoin("-", "2147483648"));
	if (sign < 0)
	{
		cpy = pf_itoa(-sign);
		if (!cpy)
			return (NULL);
		str = pf_strjoin("-", cpy);
		return (free (cpy), str);
	}
	digit = llong_digitcounter(sign);
	str = pf_calloc(digit + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[digit] = '\0';
	while (digit != 0)
	{
		str[--digit] = sign % 10 + '0';
		sign /= 10;
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
