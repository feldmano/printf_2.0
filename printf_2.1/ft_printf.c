/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/05 10:16:18 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/28 09:48:40 by ompelman      ########   odam.nl         */
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
	if (_jump_print((char *)input, &utils) == NULL)
		return (flush_buffer(&utils), -1);
	va_end(arg);
	if (flush_buffer(&utils) == false)
		return (-1);
	return ((int) utils.rtn);
}

char	*_jump_print(char *str, t_utils *utils)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (NULL);
		else if (str[i] == '%')
		{
			while (str[++i])
				if (str[i] != ' ' && (str[i + 1] < 9 || str[i + 1] > 13))
					break ;
			if (conversions(utils, (char)str[i]) == false)
				return (NULL);
		}
		else if (str[i] != '%')
			if (_noflag(utils, str[i]) == false)
				return (NULL);
	}
	return (str);
}

t_func_ptr	get_func(int c)
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
	['0'] = _zero,
	};

	return (func[c]);
}

bool	conversions(t_utils *utils, char flag)
{
	va_list	copy;

	va_copy(copy, *(utils->arg));
	if (flag == 's' || flag == 'p')
	{
		if (va_arg(copy, void *) == NULL)
		{
			va_arg(*(utils->arg), void *);
			return (get_func(flag - 32)(utils));
		}
	}
	if (flag == 'i' || flag == 'd' || flag == 'u')
	{
		if (va_arg(copy, int) == 0)
		{
			va_arg(*(utils->arg), void *);
			return (get_func('0')(utils));
		}
	}
	va_end(copy);
	if (pf_strchr("cspiduxX%", flag) != NULL)
		return (get_func(flag)(utils));
	else
		return (_noflag(utils, flag));
}

bool	flush_buffer(t_utils *utils)
{
	ssize_t		i;

	i = 0;
	i += write(1, utils->buffer, utils->offset);
	if (i == -1)
		return (false);
	else
	{
		utils->rtn += i;
		while (utils->offset > 0)
			utils->buffer[--utils->offset] = '\0';
		utils->offset = 0;
	}
	return (true);
}
