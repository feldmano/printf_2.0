/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/01 22:17:22 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/02 23:38:02 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

bool	clear_args(t_utils *utils, va_list *copy)
{
	va_end(*copy);
	va_arg(*(utils->arg), void *);
	utils->flags |= null;
	return (true);
}
