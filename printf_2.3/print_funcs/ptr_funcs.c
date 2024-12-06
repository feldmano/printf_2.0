/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ptr_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 17:22:04 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 15:14:08 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"
#include "../include/string/string.h" // for get_base

#include <stdint.h> // for uintptr

bool	_prefixcap(t_utils *utils)
{
	char	*prefix;
	int		i;

	prefix = "0X";
	i = -1;
	while (++i < 2)
	{
		utils->buffer[utils->offset] = prefix[i];
		++utils->offset;
	}
	return (true);
}

bool	_prefix(t_utils *utils)
{
	char	*prefix;
	int		i;

	prefix = "0x";
	i = -1;
	while (++i < 2)
	{
		utils->buffer[utils->offset] = prefix[i];
		++utils->offset;
	}
	return (true);
}

bool	_ptr(t_utils *utils)
{
	uintptr_t		ptr;
	int				i;

	if (_prefix(utils) == false)
		return (false);
	ptr = va_arg(*(utils->arg), uintptr_t);
	i = sizeof(uintptr_t) * 2;
	while (ptr >> (4 * --i) == 0)
		if (i == 0)
			break ;
	while (i >= 0)
	{
		utils->buffer[utils->offset] = get_base(ptr >> (4 * i) & 0XF, 'l');
		++utils->offset;
		--i;
	}
	return (true);
}

char	get_base(unsigned int unsig, int flag)
{
	const char	*low = "0123456789abcdef";
	const char	*high = "0123456789ABCDEF";

	if (flag == 'x')
		return (low[unsig]);
	return (high[unsig]);
}
