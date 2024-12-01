/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edge_funcs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 13:29:56 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/28 09:54:20 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf/ft_printf.h"
#include "../include/utils/utils.h"

bool	_nil(t_utils *utils)
{
	char	*prefix;
	int		i;

	prefix = "(nil)";
	i = -1;
	while (++i < 5)
	{
		if (utils->offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		utils->buffer[utils->offset] = prefix[i];
		++utils->offset;
	}
	return (true);
}

bool	_null(t_utils *utils)
{
	char	*prefix;
	int		i;

	prefix = "(null)";
	i = -1;
	while (++i < 6)
	{
		if (utils->offset == BUFSIZ)
			if (flush_buffer(utils) == false)
				return (false);
		utils->buffer[utils->offset] = prefix[i];
		++utils->offset;
	}
	return (true);
}

bool	_zero(t_utils *utils)
{
	if (utils->offset == BUFSIZ)
		if (flush_buffer(utils) == false)
			return (false);
	utils->buffer[utils->offset] = '0';
	++utils->offset;
	return (true);
}

bool	_pcnt(t_utils *utils)
{
	if (utils->offset > BUFSIZ - 1)
		if (flush_buffer(utils) == false)
			return (false);
	utils->buffer[utils->offset] = '%';
	++utils->offset;
	return (true);
}

bool	_noflag(t_utils *utils, char noflag)
{
	if (utils->offset > BUFSIZ - 1)
		if (flush_buffer(utils) == false)
			return (false);
	utils->buffer[utils->offset] = noflag;
	++utils->offset;
	return (true);
}
