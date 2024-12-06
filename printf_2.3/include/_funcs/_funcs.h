/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _funcs.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/01 03:28:47 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 21:46:11 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FUNCS_H
# define _FUNCS_H
# include "../ft_printf/ft_printf.h"

bool	_zero(t_utils *utils);
bool	_plus(t_utils *utils);
bool	_space(t_utils *utils);
bool	_pcnt(t_utils *utils);
bool	_char(t_utils *utils);
bool	_str(t_utils *utils);
bool	_int(t_utils *utils);
bool	_uns(t_utils *utils);
bool	_hex(t_utils *utils);
bool	_hexcap(t_utils *utils);
bool	_prefix(t_utils *utils);
bool	_prefixcap(t_utils *utils);
bool	_ptr(t_utils *utils);
bool	_nil(t_utils *utils);
bool	_null(t_utils *utils);
bool	_number_null(t_utils *utils);
bool	_positive_num_check(t_utils *utils, char sign);
bool	_noflag(t_utils *utils, char noflag);

#endif
