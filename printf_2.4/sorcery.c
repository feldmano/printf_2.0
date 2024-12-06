/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorcery.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 19:30:29 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/02 23:38:35 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h" // flush buffer
#include "funcs/_funcs.h"
#include "string/string.h"

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
	['S'] = _null,
	['P'] = _nil,
	['n'] = _null_num,
	['0'] = _zero,
	};

	return (func[c]);
}

static int	get_flag(int c)
{
	static const int	flags[127] = {
	['#'] = hash,
	['0'] = zero,
	['-'] = minus,
	[' '] = space,
	['+'] = plus,
	};

	return (flags[c]);
}

bool	set_flags(t_utils *utils, char *str, ssize_t *i)
{
	while (str[*i] && pf_strchr("#0- +123456789", str[*i]))
	{
		if (pf_strchr("#0- +", str[*i]))
			utils->flags |= get_flag(str[*i]);
		if (pf_strchr("123456789", str[*i]))
			utils->pad = utils->pad * 10 + str[*i] - 48;
		if (!str[++*i])
			return (false);
	}
	if (!pf_strchr("cspiduxX%", str[*i]))
		return (false);
	if (str[*i] == '%')
	{
		utils->flags = 0;
		utils->flags |= percent;
		return (true);
	}
	else if (utils->flags & zero || utils->flags & minus)
		if (!pf_strchr("123456789", str[*i - 1]))
			return (false);
	return (true);
}

bool	specifiers(t_utils *utils, char specifier)
{
	_null_handler(utils, specifier);
	if (utils->flags & null)
		return (true);
	if (pf_strchr("cspuidxX%", specifier))
	{
		if (specifier == 'X')
		{
			utils->flags |= cap;
			specifier = 'x';
		}
		if (!pf_strchr("sp", specifier))
			_padding(utils);
		get_func(specifier)(utils);
		if (utils->flags & mal_loc)
			return (false);
		utils->pad = reset;
	}
	else
	{
		_pcnt(utils);
		_no_specifier(utils, specifier);
	}
	return (true);
}

bool	_null_handler(t_utils *utils, char flag)
{
	va_list	copy;

	utils->flags &= ~null;
	va_copy(copy, *(utils->arg));
	if (flag == 's' || flag == 'p')
		if (va_arg(copy, void *) == NULL)
			return (clear_args(utils, &copy) && get_func(flag - 32)(utils));
	if (flag == 'i' || flag == 'd' || flag == 'u')
		if (va_arg(copy, int) == 0)
			return (clear_args(utils, &copy) && _null_num(utils));
	if (flag == 'x' || flag == 'X')
		if (va_arg(copy, unsigned int) == 0)
			return (clear_args(utils, &copy) && _zero(utils));
	return (va_end(copy), true);
}
