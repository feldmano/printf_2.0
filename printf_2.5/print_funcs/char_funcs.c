/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_funcs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/03 12:42:58 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/03 12:44:57 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

bool	_pcnt(t_utils *utils)
{
	utils->buffer[utils->offset] = '%';
	++utils->offset;
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

bool	_minus(t_utils *utils)
{
	utils->buffer[utils->offset] = '-';
	++utils->offset;
	return (true);
}
