/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorcery.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 19:30:29 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 22:06:54 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf/ft_printf.h" // flush buffer
#include "include/_funcs/_funcs.h"
#include "include/string/string.h"

static t_func_ptr	get_func(int c)
{
	static const t_func_ptr	func[127] = {
	['%'] = _pcnt,
	['i'] = _int,
	['d'] = _int,
	['c'] = _char,
	['s'] = _str,
	['p'] = _ptr,
	['u'] = _uns,
	['x'] = _hex,
	['X'] = _hexcap,
	['S'] = _null,
	['P'] = _nil,
	['n'] = _number_null,
	['0'] = _zero,
	};

	return (func[c]);
}

bool	flags(t_utils *utils, char *str, ssize_t *i)
{
	while (str[*i] && pf_strchr("#0- +", str[*i]) != NULL)
	{
		if (str[*i] == '#')
			utils->flags |= 1;
		if (str[*i] == '0')
			utils->flags |= 2;
		if (str[*i] == '-')
			utils->flags |= 4;
		if (str[*i] == ' ')
			utils->flags |= 8;
		if (str[*i] == '+')
			utils->flags |= 16;
		if (pf_strchr("0-", str[*i]) != NULL)
		{
			while (str[++*i] && str[*i] >= 48 && str[*i] <= 57)
				utils->pad = utils->pad * 10 + str[*i] - 48;
			if (!str[*i] || (!utils->pad && !pf_strchr("cspiduxX%", str[*i])))
				return (false);
		}
		else if (!str[++*i])
			return (false);
	}
	return (true);
}

bool	_padding(t_utils *utils)
{
	int	padding;

	padding = utils->pad;
	while (padding > 0)
	{
		if (utils->flags & 4)
			utils->buffer[utils->offset] = ' ';
		else if (utils->flags & 2)
			utils->buffer[utils->offset] = '0';
		++utils->offset;
		--padding;
	}
	return (true);
}

bool	_null_handler(t_utils *utils, char flag)
{
	va_list	copy;

	va_copy(copy, *(utils->arg));
	if (flag == 's' || flag == 'p')
		if (va_arg(copy, void *) == NULL)
		{
			va_arg(*(utils->arg), void *);
			utils->flags |= 32;
			return (va_end(copy), get_func(flag - 32)(utils));
		}
	if (flag == 'i' || flag == 'd' || flag == 'u')
		if (va_arg(copy, int) == 0)
		{
			va_arg(*(utils->arg), void *);
			utils->flags |= 32;
			return (va_end(copy), _number_null(utils));
		}
	if (flag == 'x' || flag == 'X')
		if (va_arg(copy, unsigned int) == 0)
		{
			va_arg(*(utils->arg), void *);
			utils->flags |= 32;
			return (va_end(copy), _zero(utils));
		}
	return (va_end(copy), true);
}

bool	specifiers(t_utils *utils, char flag)
{
	int	buffer_call;

	buffer_call = 20 + utils->pad;
	if (utils->offset > BUFSIZ - buffer_call)
		if (flush_buffer(utils) == false)
			return (false);
	_padding(utils);
	utils->flags &= ~32;
	_null_handler(utils, flag);
	if (utils->flags & 32)
		return (true);
	if (get_func(flag)(utils) == false)
		return (false);
	utils->flags = 0;
	utils->pad = 0;
	return (true);
}
