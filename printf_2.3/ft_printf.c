/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/05 10:16:18 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 22:02:28 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf/ft_printf.h" // t_utils, BUFSIZ
#include "include/_funcs/_funcs.h" // _pcnt, _noflag, flags, specifiers
#include "include/string/string.h" // pf_strchr

__attribute__((format(printf, 1, 2)))
int	ft_printf(const char *input, ...)
{
	t_utils				utils;
	va_list				arg;

	utils = (t_utils){};
	utils.buffer = (char [BUFSIZ]){};
	utils.arg = &arg;
	va_start(arg, input);
	if (jump_print((char *)input, &utils) == NULL)
		return (flush_buffer(&utils), -1);
	va_end(arg);
	if (flush_buffer(&utils) == false)
		return (-1);
	return ((int) utils.rtn);
}

char	*jump_print(char *str, t_utils *utils)
{
	ssize_t		i;
	ssize_t		k;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			k = i;
			if (pf_strchr("#0- +cspuidxX%", str[++i]) && flags(utils, str, &i))
			{
				if (specifiers(utils, str[i]) == false)
					return (NULL);
			}
			else
			{
				utils->pad = 0;
				_pcnt(utils);
				i = k;
			}
		}
		else if (str[i] == '%' || _noflag(utils, str[i]) == false)
			return (NULL);
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
