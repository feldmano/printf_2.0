/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/05 10:16:18 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/10 15:17:36 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h" // t_utils, BUFSIZ
#include "funcs/_funcs.h" // _pcnt, _noflag, flags, specifiers
#include "string/string.h" // pf_strchr

__attribute__((format(printf, 1, 2)))
int	ft_printf(const char *input, ...)
{
	t_utils		utils;
	va_list		arg;
	ssize_t		err;

	err = -1;
	if (!input)
		return (err);
	utils = (t_utils){};
	utils.buffer = (char [BUFSIZ]){};
	utils.arg = &arg;
	va_start(arg, input);
	if (jump_print((char *)input, &utils) == NULL)
		return (flush_buffer(&utils), err);
	va_end(arg);
	if (flush_buffer(&utils) == false)
		return (err);
	return ((int) utils.rtn);
}

char	*jump_print(char *str, t_utils *utils)
{
	ssize_t		i;
	ssize_t		k;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '%' || (utils->flags & percent) == 1)
			_no_specifier(utils, str[i]);
		if (str[i] == '%')
		{
			if (!str[++i])
				return (NULL);
			utils->flags = reset;
			utils->pad = reset;
			k = i;
			if (set_flags(utils, str, &i) == false)
				i = k;
			if (specifiers(utils, str[i]) == false)
				return (NULL);
		}
	}
	return (str);
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
