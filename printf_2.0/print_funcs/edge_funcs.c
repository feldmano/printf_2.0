/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edge_funcs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 13:29:56 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/23 13:37:19 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf/ft_printf.h"
#include "../include/utils/utils.h"
#include <stdint.h> // for uintptr

bool	_prefix(t_utils *utils)
{
	int		local_offset;
	char	*local_buffer;
	char	*prefix;
	int		i;

	local_buffer = utils->buffer;
	local_offset = utils->offset;
	prefix = "0x";
	i = -1;
	while (++i < 2)
	{
		if (local_offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		local_buffer[local_offset] = prefix[i];
		++local_offset;
	}
	utils->offset = local_offset;
	return (true);
}

bool	_ptr(t_utils *utils)
{
	int				local_offset;
	char			*local_buffer;
	uintptr_t		ptr;
	int				i;

	ptr = va_arg(*(utils->arg), uintptr_t);
	i = sizeof(uintptr_t) * 2;
	while (ptr >> (4 * --i) == 0)
		if (i == 0)
			return (_nil(utils));
	if (_prefix(utils) == false)
		return (false);
	local_buffer = utils->buffer;
	local_offset = utils->offset;
	while (i >= 0)
	{
		if (local_offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		local_buffer[local_offset] = get_base(ptr >> (4 * i) & 0XF, 'l');
		++local_offset;
		--i;
	}
	utils->offset = local_offset;
	return (true);
}

bool	_nil(t_utils *utils)
{
	int		local_offset;
	char	*local_buffer;
	char	*prefix;
	int		i;

	local_buffer = utils->buffer;
	local_offset = utils->offset;
	prefix = "(nil)";
	i = -1;
	while (++i < 5)
	{
		if (local_offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		local_buffer[local_offset] = prefix[i];
		++local_offset;
	}
	utils->offset = local_offset;
	return (true);
}

bool	_nothing(t_utils *utils)
{
	++utils->offset;
	return (true);
}
