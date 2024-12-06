/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/05 11:00:17 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/26 15:08:02 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>  // for ssize_t, size_t
# include <stdlib.h> // for free
# include <stdio.h> // for BUFSIZ
# include <stdarg.h> 
# include <stdbool.h>

typedef struct s_utils
{
	char			*buffer;
	int				offset;
	ssize_t			rtn;
	va_list			*arg;

}	t_utils;

typedef bool	(*t_func_ptr)(t_utils *);

int		ft_printf(const char *input, ...);
char	*_jump_print(char *str, t_utils *utils);
bool	flush_buffer(t_utils *utils);
bool	conversions(t_utils *utils, char flag);
bool	_noflag(t_utils *utils, char noflag);
bool	_pcnt(t_utils *utils);
bool	_char(t_utils *utils);
bool	_str(t_utils *utils);
bool	_int(t_utils *utils);
bool	_uns(t_utils *utils);
bool	_hex(t_utils *utils);
bool	_hexcap(t_utils *utils);
bool	_prefix(t_utils *utils);
bool	_ptr(t_utils *utils);
bool	_nil(t_utils *utils);
bool	_null(t_utils *utils);
bool	_zero(t_utils *utils);

#endif
