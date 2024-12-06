/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:14:27 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/03 00:03:48 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h" // for t_utils, va_arg 
#include "string/string.h" // for itoa, untoa, get_base, pf_strlen
#include "funcs/_funcs.h" // for _space, _plus

bool	_positive_num_check(t_utils *utils, char sign)
{
	if (sign != '-')
	{
		if ((utils->flags & plus))
			return (_plus(utils));
		else if ((utils->flags & space))
			return (_space(utils));
	}
	return (false);
}

bool	_int(t_utils *utils)
{
	char	*str;
	int		slen;
	int		i;

	str = pf_itoa(va_arg(*(utils->arg), int));
	if (!str)
	{
		utils->flags |= mal_loc;
		return (false);
	}
	slen = pf_strlen(str);
	utils->offset -= utils->pad;
	if ((utils->flags & (zero | minus)) == zero && utils->pad >= slen)
		utils->offset += utils->pad - slen;
	if (_positive_num_check(utils, str[0]))
		--utils->pad;
	i = -1;
	while (str[++i])
	{
		utils->buffer[utils->offset] = str[i];
		++utils->offset;
	}
	if (utils->flags & minus && utils->pad >= slen)
		utils->offset += utils->pad - slen;
	return (free(str), true);
}

bool	_uns(t_utils *utils)
{
	char	*str;
	int		slen;
	int		i;

	str = pf_utoa(va_arg(*(utils->arg), unsigned int));
	if (!str)
	{
		utils->flags |= mal_loc;
		return (false);
	}
	slen = pf_strlen(str);
	utils->offset -= utils->pad;
	if ((utils->flags & (zero | minus)) == zero && utils->pad >= slen)
		utils->offset += utils->pad - slen;
	i = -1;
	while (str[++i])
	{
		utils->buffer[utils->offset] = str[i];
		++utils->offset;
	}
	if (utils->flags & minus && utils->pad >= slen)
		utils->offset += utils->pad - slen;
	return (free(str), true);
}

bool	_hex(t_utils *utils)
{
	unsigned int	hex;
	int				i;
	int				k;

	hex = va_arg(*(utils->arg), unsigned int);
	i = sizeof(hex) * 2 - 1;
	utils->offset -= utils->pad;
	while (hex >> (4 * i) == 0 && i > 0)
		--i;
	k = i;
	if ((utils->flags & (zero | minus)) == zero && utils->pad >= k)
		utils->offset += utils->pad - k - 1;
	if (utils->flags & hash)
		_hash(utils);
	while (i >= 0)
	{
		utils->buffer[utils->offset] = base(hex >> (4 * i) & 0XF, utils->flags);
		++utils->offset;
		--i;
	}
	if (utils->flags & minus && utils->pad >= k)
		utils->offset += utils->pad - k;
	return (true);
}
