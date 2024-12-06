/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/05 10:16:18 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/23 15:33:56 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf/ft_printf.h"
#include "include/utils/utils.h"

__attribute__((format(printf, 1, 2)))
int	ft_printf(const char *input, ...)
{
	t_utils				utils;
	va_list				arg;

	utils = (t_utils){};
	utils.buffer = (char [BUFSIZ]){};
	utils.arg = &arg;
	va_start(arg, input);
	_jump_print(input, &utils);
	va_end(arg);
	return ((int) utils.rtn);
}

void	_jump_print(const char *str, t_utils *utils)
{
	ssize_t		index;

	index = 0;
	while (str[index])
	{
		if (utils->offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return ;
		if (str[index] != '%')
		{
			utils->buffer[utils->offset] = str[index];
			++utils->offset;
		}
		else if (str[index] == '%')
		{
			if (conversions(str[index + 1], utils) == false)
				if (flush_buffer(utils) == false)
					return ;
			++index;
		}
		++index;
	}
	flush_buffer(utils);
}

t_func_ptr	get_func(const int c)
{
	static const t_func_ptr	func[127] = {
	[' '] = _space,
	['%'] = _pcnt,
	['c'] = _char,
	['s'] = _str,
	['p'] = _ptr,
	['u'] = _uns,
	['x'] = _hex,
	['X'] = _hexcap
	};

	return (func[c]);
}

bool	conversions(const char c, t_utils *utils)
{
	va_list		copy;

	if (pf_strchr("cspuxX% ", c) == NULL)
		return (false);
	va_copy(copy, *(utils->arg));
	if (c == 'c' && va_arg(copy, int) == 0)
	{
		va_arg(*(utils->arg), int);
		va_end(copy);
		return (_nothing(utils));
	}
	get_func(c)(utils);
	va_end(copy);
	return (true);
}

bool	flush_buffer(t_utils *utils)
{
	ssize_t		glyphs;
	int			local_offset;
	char		*local_buffer;

	glyphs = 0;
	local_offset = utils->offset;
	local_buffer = utils->buffer;
	glyphs += write(1, local_buffer, local_offset);
	if (glyphs == -1)
		return (false);
	else
	{
		utils->rtn += glyphs;
		while (local_offset > 0)
			local_buffer[--local_offset] = '\0';
		utils->offset = 0;
	}
	return (true);
}
