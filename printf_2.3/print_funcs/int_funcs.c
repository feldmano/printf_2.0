/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:14:27 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 15:16:20 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h" // for t_utils, va_arg 
#include "../include/string/string.h" // for itoa, untoa, get_base, pf_strlen
#include "../include/_funcs/_funcs.h" // for _space, _plus

bool	_positive_num_check(t_utils *utils, char sign)
{
	if (sign != '-')
	{
		if ((utils->flags & 16))
			return (_plus(utils));
		else if ((utils->flags & 8))
			return (_space(utils));
	}
	return (false);
}

bool	_int(t_utils *utils)
{
	char	*str;
	int		i;

	str = itoa(va_arg(*(utils->arg), int));
	if (!str)
		return (false);
	utils->offset -= utils->pad;
	_positive_num_check(utils, str[0]);
	if ((utils->flags & 2) && !(utils->flags & 4))
		if (utils->pad >= pf_strlen(str))
			utils->offset += (utils->pad - pf_strlen(str));
	i = -1;
	while (str[++i])
	{
		utils->buffer[utils->offset] = str[i];
		++utils->offset;
	}
	if (utils->pad >= pf_strlen(str))
		utils->offset = ++utils->pad;
	return (free(str), true);
}

bool	_uns(t_utils *utils)
{
	char	*str;
	int		i;

	str = utoa(va_arg(*(utils->arg), unsigned int));
	if (!str)
		return (false);
	utils->offset -= utils->pad;
	if ((utils->flags & 2) && !(utils->flags & 4))
		if (utils->pad >= pf_strlen(str))
			utils->offset += utils->pad - pf_strlen(str);
	i = -1;
	while (str[++i])
	{
		utils->buffer[utils->offset] = str[i];
		++utils->offset;
	}
	if (utils->pad >= pf_strlen(str))
		utils->offset = ++utils->pad;
	return (free(str), true);
}

bool	_hex(t_utils *utils)
{
	unsigned int	hex;
	int				i;
	int				k;

	hex = va_arg(*(utils->arg), unsigned int);
	i = sizeof(unsigned int) * 2;
	utils->offset -= utils->pad;
	while (hex >> (4 * --i) == 0)
		if (i == 0)
			break ;
	k = i;
	if (utils->flags & 1)
		_prefix(utils);
	if ((utils->flags & 2) && !(utils->flags & 4))
		if (utils->pad >= i)
			utils->offset += utils->pad - i - 3;
	while (i >= 0)
	{
		utils->buffer[utils->offset] = get_base(hex >> (4 * i) & 0XF, 'x');
		++utils->offset;
		--i;
	}
	if (utils->pad >= k)
		utils->offset = ++utils->pad;
	return (true);
}

bool	_hexcap(t_utils *utils)
{
	unsigned int	hex;
	int				i;
	int				k;

	hex = va_arg(*(utils->arg), unsigned int);
	i = sizeof(unsigned int) * 2;
	utils->offset -= utils->pad;
	while (hex >> (4 * --i) == 0)
		if (i == 0)
			break ;
	k = i;
	if (utils->flags & 1)
		_prefixcap(utils);
	if ((utils->flags & 2) && !(utils->flags & 4))
		if (utils->pad >= i)
			utils->offset += utils->pad - i - 3;
	while (i >= 0)
	{
		utils->buffer[utils->offset] = get_base(hex >> (4 * i) & 0XF, 'X');
		++utils->offset;
		--i;
	}
	if (utils->pad >= k)
		utils->offset = ++utils->pad;
	return (true);
}
