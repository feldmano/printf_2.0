/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_funcs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:14:27 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/03 18:30:15 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h" // for t_utils, va_arg 
#include "string/string.h" // for itoa, untoa, get_base, pf_strlen
#include "funcs/_funcs.h" // for _space, _plus

static bool	_put_string(t_utils *utils, char *str);
static bool	_put_sign_or_space(t_utils *utils, char *str);

bool	_uns(t_utils *utils)
{
	char	*str;
	int		slen;

	str = pf_utoa(va_arg(*(utils->arg), unsigned int));
	if (!str)
	{
		utils->flags |= mal_loc;
		return (false);
	}
	slen = pf_strlen(str);
	utils->offset -= utils->pad;
	if (utils->pad >= slen && (utils->flags & zero) && !(utils->flags & dash))
		utils->offset += utils->pad - slen;
	_put_string(utils, str);
	if (utils->pad >= slen && (utils->flags & dash))
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
	if (utils->pad >= k && (utils->flags & zero) && !(utils->flags & dash))
		utils->offset += utils->pad - k - 1;
	if (utils->flags & hash)
		_hash(utils);
	while (i >= 0)
	{
		utils->buffer[utils->offset] = base(hex >> (4 * i) & 0XF, utils->flags);
		++utils->offset;
		--i;
	}
	if ((utils->flags & dash) && utils->pad >= k)
		utils->offset += utils->pad - k;
	return (true);
}

bool	_int(t_utils *utils)
{
	char	*str;
	int		slen;

	str = pf_itoa(va_arg(*(utils->arg), int));
	if (!str)
	{
		utils->flags |= mal_loc;
		return (false);
	}
	slen = pf_strlen(str);
	utils->offset -= utils->pad;
	if (str[0] == '-' || (utils->flags & plus) || (utils->flags & space))
		_put_sign_or_space(utils, str);
	if ((utils->flags & zero) && !(utils->flags & dash))
		if (utils->pad >= slen)
			utils->offset += utils->pad - slen;
	_put_string(utils, str);
	if ((utils->flags & dash))
		if (utils->pad >= slen)
			utils->offset += utils->pad - slen;
	return (free(str), true);
}

static bool	_put_string(t_utils *utils, char *str)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
	{
		utils->buffer[utils->offset] = str[i];
		++utils->offset;
	}
	return (true);
}

static bool	_put_sign_or_space(t_utils *utils, char *str)
{
	ssize_t	i;

	if (str[0] == '-')
	{
		i = -1;
		while (str[++i])
			if (str[i + 1])
				str[i] = str[i + 1];
		str[i - 1] = '\0';
		_minus(utils);
	}
	else
	{
		if ((utils->flags & plus))
			_plus(utils);
		else if ((utils->flags & space))
			_space(utils);
	}
	if (utils->pad > 0 && (utils->flags & zero) && !(utils->flags & dash))
		--utils->offset;
	return (true);
}
