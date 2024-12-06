/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:46:24 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/23 15:41:57 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf/ft_printf.h" // flush buffer
#include "../include/utils/utils.h"

bool	_space(t_utils *utils)
{
	int		local_offset;

	local_offset = utils->offset;
	if (local_offset == BUFSIZ)
		if (flush_buffer(utils) == false)
			return (false);
	utils->buffer[local_offset] = '%';
	utils->buffer[++local_offset] = ' ';
	utils->offset += 2;
	return (true);
}

bool	_pcnt(t_utils *utils)
{
	int		local_offset;

	local_offset = utils->offset;
	if (local_offset == BUFSIZ)
		if (flush_buffer(utils) == false)
			return (false);
	utils->buffer[local_offset] = '%';
	++utils->offset;
	return (true);
}

bool	_char(t_utils *utils)
{
	int		local_offset;
	char	c;

	c = (char) va_arg(*(utils->arg), int);
	local_offset = utils->offset;
	if (local_offset == BUFSIZ)
		if (flush_buffer(utils) == false)
			return (false);
	utils->buffer[local_offset] = c;
	++utils->offset;
	return (true);
}

bool	_str(t_utils *utils)
{
	int		local_offset;
	char	*local_buffer;
	char	*str;
	int		i;

	str = va_arg(*(utils->arg), char *);
	local_offset = utils->offset;
	local_buffer = utils->buffer;
	i = -1;
	while (str[++i])
	{
		if (local_offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		local_buffer[local_offset] = str[i];
		++local_offset;
	}
	utils->offset = local_offset;
	return (true);
}
