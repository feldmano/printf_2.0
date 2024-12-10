/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 18:51:23 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/10 14:12:33 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "funcs/_funcs.h" // for _space, _zero

bool	_padding(t_utils *utils)
{
	int	padding;

	padding = utils->pad;
	while (--padding >= 0)
	{
		if (utils->flags & zero && !(utils->flags & dash))
			_zero(utils);
		else
			_space(utils);
	}
	return (true);
}

bool	_put_sign_or_space(t_utils *utils, char *str)
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
