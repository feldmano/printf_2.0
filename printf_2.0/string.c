/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:23:05 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/23 13:36:47 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
#include <stdlib.h> // for free
#include "include/utils/utils.h" // for pf_calloc, pf_strjoin, digitcounter

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

char	get_base(unsigned int unsig, int flag)
{
	const char	*low = "0123456789abcdef";
	const char	*high = "0123456789ABCDEF";

	if (flag == 'l')
		return (low[unsig]);
	return (high[unsig]);
}
