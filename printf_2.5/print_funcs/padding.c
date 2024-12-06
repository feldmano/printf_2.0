/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 18:51:23 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/03 16:21:03 by ompelman      ########   odam.nl         */
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
		if (utils->flags & dash)
			_space(utils);
		else if (utils->flags & zero)
			_zero(utils);
	}
	return (true);
}
