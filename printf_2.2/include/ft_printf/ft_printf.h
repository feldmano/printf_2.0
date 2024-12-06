/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/05 11:00:17 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 14:06:00 by ompelman      ########   odam.nl         */
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
	int				flags;
	int				pad;
	ssize_t			rtn;
	va_list			*arg;

}	t_utils;

typedef bool	(*t_func_ptr)(t_utils *);

int		ft_printf(const char *input, ...);
char	*jump_print(char *str, t_utils *utils);
bool	flags(t_utils *utils, char *str, ssize_t *i);
bool	specifiers(t_utils *utils, char flag);
bool	_null_handler(t_utils *utils, char flag);
bool	_padding(t_utils *utils);
bool	flush_buffer(t_utils *utils);

#endif
