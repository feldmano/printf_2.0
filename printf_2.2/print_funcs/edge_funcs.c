/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edge_funcs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 13:29:56 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 11:10:42 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"

bool	_nil(t_utils *utils)
{
	char	*prefix;
	int		i;

	prefix = "(nil)";
	i = -1;
	while (++i < 5)
	{
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
		utils->buffer[utils->offset] = prefix[i];
		++utils->offset;
	}
	return (true);
}

bool	_number_null(t_utils *utils)
{
	utils->buffer[utils->offset] = '0';
	++utils->offset;
	return (true);
}

bool	_pcnt(t_utils *utils)
{
	utils->buffer[utils->offset] = '%';
	++utils->offset;
	return (true);
}