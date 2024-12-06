/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 18:51:23 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/02 23:47:38 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "funcs/_funcs.h"

bool	_padding(t_utils *utils)
{
	int	padding;

	padding = utils->pad;
	while (--padding >= 0)
	{
		if (utils->flags & minus)
			_space(utils);
		else if (utils->flags & zero)
			_zero(utils);
	}
	return (true);
}

bool	_hash(t_utils *utils)
{
	char	*prefix;
	int		i;

	prefix = "0x";
	if (utils->flags & cap)
		prefix = "0X";
	i = -1;
	while (++i < 2)
	{
		utils->buffer[utils->offset] = prefix[i];
		++utils->offset;
	}
	return (true);
}

bool	_zero(t_utils *utils)
{
	utils->buffer[utils->offset] = '0';
	++utils->offset;
	return (true);
}

bool	_space(t_utils *utils)
{
	utils->buffer[utils->offset] = ' ';
	++utils->offset;
	return (true);
}

bool	_plus(t_utils *utils)
{
	utils->buffer[utils->offset] = '+';
	++utils->offset;
	return (true);
}
