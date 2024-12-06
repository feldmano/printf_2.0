/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ptr_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 17:22:04 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/28 09:50:34 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf/ft_printf.h"
#include "../include/utils/utils.h"
#include <stdint.h> // for uintptr

bool	_prefix(t_utils *utils)
{
	char	*prefix;
	int		i;

	prefix = "0x";
	if (utils->offset > BUFSIZ - 2)
		if (flush_buffer(utils) == false)
			return (false);
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
	if (utils->offset > BUFSIZ - i)
		if (flush_buffer(utils) == false)
			return (false);
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
