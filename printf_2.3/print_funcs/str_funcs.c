/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:46:24 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 14:11:58 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h" // flush buffer
#include "../include/string/string.h" // pf_strlen
#include "../include/_funcs/_funcs.h" // _space

bool	_noflag(t_utils *utils, char noflag)
{
	utils->buffer[utils->offset] = noflag;
	++utils->offset;
	return (true);
}

bool	_char(t_utils *utils)
{
	char	c;

	utils->offset -= utils->pad;
	c = (char) va_arg(*(utils->arg), int);
	if (!c)
		return (NULL);
	if ((utils->flags & 2) && !(utils->flags & 4))
		while (utils->pad-- > 1)
			_space(utils);
	utils->buffer[utils->offset] = c;
	++utils->offset;
	return (true);
}

bool	_str(t_utils *utils)
{
	char	*str;
	int		i;

	utils->offset -= utils->pad;
	str = va_arg(*(utils->arg), char *);
	if (!str)
		return (false);
	if ((utils->flags & 2) && !(utils->flags & 4))
		while (utils->pad-- > pf_strlen(str))
			_space(utils);
	if (str[0] == '\0')
		return (_space(utils));
	i = -1;
	while (str[++i])
	{
		if (utils->offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		utils->buffer[utils->offset] = str[i];
		++utils->offset;
	}
	return (true);
}
