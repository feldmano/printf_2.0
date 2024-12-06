/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:46:24 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/02 23:37:56 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h" // flush buffer
#include "string/string.h" // pf_strlen
#include "funcs/_funcs.h" // _space

bool	_no_specifier(t_utils *utils, char no_specifier)
{
	utils->buffer[utils->offset] = no_specifier;
	++utils->offset;
	return (true);
}

bool	_char(t_utils *utils)
{
	char	c;

	c = (char) va_arg(*(utils->arg), int);
	if (!c)
		return (NULL);
	if (left_padding(utils, 1) == false)
		return (false);
	utils->buffer[utils->offset] = c;
	++utils->offset;
	if (right_padding(utils, 1) == false)
		return (false);
	return (true);
}

bool	_str(t_utils *utils)
{
	char	*str;
	int		slen;
	int		i;

	str = va_arg(*(utils->arg), char *);
	if (!str)
		return (false);
	slen = pf_strlen(str);
	if (left_padding(utils, slen) == false)
		return (false);
	i = 0;
	while (str[i])
	{
		if (utils->offset == BUFSIZ - slen)
			if (flush_buffer(utils) == false)
				return (false);
		utils->buffer[utils->offset] = str[i];
		++utils->offset;
		++i;
	}
	if (right_padding(utils, slen) == false)
		return (false);
	return (true);
}

bool	left_padding(t_utils *utils, int slen)
{
	if ((utils->flags & (zero | minus)) == zero && utils->pad >= slen)
	{
		while (utils->pad-- > slen)
		{
			if (utils->offset == BUFSIZ)
				if (flush_buffer(utils) == false)
					return (false);
			_space(utils);
		}
	}
	return (true);
}

bool	right_padding(t_utils *utils, int slen)
{
	if (utils->flags & minus)
	{
		while (utils->pad-- > slen)
		{
			if (utils->offset == BUFSIZ)
				if (flush_buffer(utils) == false)
					return (false);
			_space(utils);
		}
	}
	return (true);
}
