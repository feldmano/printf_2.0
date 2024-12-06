/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ptr_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 17:22:04 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/02 23:37:51 by ompelman      ########   odam.nl         */
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

	utils->flags |= ~hash;
	_hash(utils);
	ptr = va_arg(*(utils->arg), uintptr_t);
	i = sizeof(uintptr_t) * 2;
	while (ptr >> (4 * --i) == 0)
		if (i == 0)
			break ;
	while (i >= 0)
	{
		utils->buffer[utils->offset] = base(ptr >> (4 * i) & 0XF, utils->flags);
		++utils->offset;
		--i;
	}
	return (true);
}
