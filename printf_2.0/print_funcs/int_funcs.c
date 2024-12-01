/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:14:27 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/23 15:42:34 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf/ft_printf.h" // for BUFIZ, flush buffer  
#include "../include/utils/utils.h" // for itoa, untoa, get_base

bool	_int(t_utils *utils)
{
	int		local_offset;
	char	*local_buffer;
	char	*str;
	int		i;

	str = itoa(va_arg(*(utils->arg), int));
	local_offset = utils->offset;
	local_buffer = utils->buffer;
	i = -1;
	while (str[++i])
	{
		if (local_offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		local_buffer[local_offset] = str[i];
		++local_offset;
	}
	utils->offset = local_offset;
	free (str);
	return (true);
}

bool	_uns(t_utils *utils)
{
	int		local_offset;
	char	*local_buffer;
	char	*str;
	int		i;

	str = utoa(va_arg(*(utils->arg), unsigned));
	local_offset = utils->offset;
	local_buffer = utils->buffer;
	i = -1;
	while (str[++i])
	{
		if (local_offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		local_buffer[local_offset] = str[i];
		++local_offset;
	}
	utils->offset = local_offset;
	free (str);
	return (true);
}

bool	_hex(t_utils *utils)
{
	int				local_offset;
	char			*local_buffer;
	unsigned int	hex;
	int				i;

	hex = va_arg(*(utils->arg), unsigned int);
	if (!hex)
		return (false);
	local_buffer = utils->buffer;
	local_offset = utils->offset;
	i = sizeof(unsigned int) * 2;
	while (hex >> (4 * --i) == 0)
		if (i == 0)
			break ;
	while (i >= 0)
	{
		if (local_offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		local_buffer[local_offset] = get_base(hex >> (4 * i) & 0XF, 'l');
		++local_offset;
		--i;
	}
	utils->offset = local_offset;
	return (true);
}

bool	_hexcap(t_utils *utils)
{
	int				local_offset;
	char			*local_buffer;
	unsigned int	hex;
	int				i;

	hex = va_arg(*(utils->arg), unsigned);
	if (!hex)
		return (false);
	local_buffer = utils->buffer;
	local_offset = utils->offset;
	i = sizeof(unsigned) * 2;
	while (hex >> (4 * --i) == 0)
		if (i == 0)
			break ;
	while (i >= 0)
	{
		if (local_offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		local_buffer[local_offset] = get_base(hex >> (4 * i) & 0XF, 'u');
		++local_offset;
		--i;
	}
	utils->offset = local_offset;
	return (true);
}
