/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:14:27 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/28 09:53:06 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf/ft_printf.h" // for BUFIZ, flush buffer  
#include "../include/utils/utils.h" // for itoa, untoa, get_base

bool	_int(t_utils *utils)
{
	char	*str;
	int		i;

	str = itoa(va_arg(*(utils->arg), int));
	if (utils->offset > BUFSIZ - 20)
		if (flush_buffer(utils) == false)
			return (free (str), false);
	i = -1;
	while (str[++i])
	{
		utils->buffer[utils->offset] = str[i];
		++utils->offset;
	}
	free (str);
	return (true);
}

bool	_uns(t_utils *utils)
{
	char	*str;
	int		i;

	str = utoa(va_arg(*(utils->arg), unsigned int));
	if (utils->offset > BUFSIZ - 20)
		if (flush_buffer(utils) == false)
			return (free(str), false);
	i = -1;
	while (str[++i])
	{
		utils->buffer[utils->offset] = str[i];
		++utils->offset;
	}
	free (str);
	return (true);
}

bool	_hex(t_utils *utils)
{
	unsigned int	hex;
	int				i;

	hex = va_arg(*(utils->arg), unsigned int);
	i = sizeof(unsigned int) * 2;
	if (utils->offset > BUFSIZ - i)
		if (flush_buffer(utils) == false)
			return (false);
	while (hex >> (4 * --i) == 0)
		if (i == 0)
			break ;
	while (i >= 0)
	{
		utils->buffer[utils->offset] = get_base(hex >> (4 * i) & 0XF, 'l');
		++utils->offset;
		--i;
	}
	return (true);
}

bool	_hexcap(t_utils *utils)
{
	unsigned int	hex;
	int				i;

	hex = va_arg(*(utils->arg), unsigned);
	i = sizeof(unsigned) * 2;
	if (utils->offset > BUFSIZ - i)
		if (flush_buffer(utils) == false)
			return (false);
	while (hex >> (4 * --i) == 0)
		if (i == 0)
			break ;
	while (i >= 0)
	{
		utils->buffer[utils->offset] = get_base(hex >> (4 * i) & 0XF, 'u');
		++utils->offset;
		--i;
	}
	return (true);
}
