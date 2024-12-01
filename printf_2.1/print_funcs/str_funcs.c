/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:46:24 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/28 09:47:44 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf/ft_printf.h" // flush buffer
#include "../include/utils/utils.h"

bool	_char(t_utils *utils)
{
	char	c;

	c = (char) va_arg(*(utils->arg), int);
	if (utils->offset == BUFSIZ)
		if (flush_buffer(utils) == false)
			return (false);
	utils->buffer[utils->offset] = c;
	++utils->offset;
	return (true);
}

bool	_str(t_utils *utils)
{
	char	*str;
	int		i;

	str = va_arg(*(utils->arg), char *);
	if (str[0] == '\0')
		return (true);
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
