/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ptr_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 17:22:04 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/10 15:31:41 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "string/string.h" // for get_base
#include "funcs/_funcs.h" // for _hash
#include <stdint.h> // for uintptr

bool	_ptr(t_utils *utils)
{
	uintptr_t		ptr;
	int				i;

	_prefix(utils);
	ptr = va_arg(*(utils->arg), uintptr_t);
	i = sizeof(uintptr_t) * 2;
	while (ptr >> (4 * --i) == 0)
		if (i == 0)
			break ;
	while (i >= 0)
	{
		utils->buffer[utils->offset] = base(utils, ptr >> (4 * i));
		++utils->offset;
		--i;
	}
	return (true);
}

bool	_prefix(t_utils *utils)
{
	char	*prefix;
	int		i;

	prefix = "0x";
	if (utils->flags & cap)
		prefix = "0X";
	i = -1;
	while (++i < 2)
	{
		utils->buffer[utils->offset] = prefix[i];
		++utils->offset;
	}
	return (true);
}

char	base( t_utils *utils, unsigned int unsign)
{
	const char	*low = "0123456789abcdef";
	const char	*high = "0123456789ABCDEF";

	if (utils->flags & cap)
		return (high[unsign & 0XF]);
	return (low[unsign & 0xf]);
}
