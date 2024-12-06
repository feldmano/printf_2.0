/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   no_specifier.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/03 12:48:16 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/03 12:54:22 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

bool	_no_specifier(t_utils *utils, char no_specifier)
{
	utils->buffer[utils->offset] = no_specifier;
	++utils->offset;
	return (true);
}
