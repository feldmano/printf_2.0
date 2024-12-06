/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 18:51:23 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 15:14:47 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"

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
