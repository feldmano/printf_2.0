/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/05 11:00:17 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/02 23:45:06 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// unsigned char i : 1
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

typedef enum e_flags
{
	reset	= 0,
	hash	= 1 << 0,
	zero	= 1 << 1,
	minus	= 1 << 2,
	space	= 1 << 3,
	plus	= 1 << 4,
	null	= 1 << 5,
	mal_loc	= 1 << 6,
	cap		= 1 << 7,
	percent	= 1 << 8,
}	t_flags;

typedef bool	(*t_func_ptr)(t_utils *);

int		ft_printf(const char *input, ...);
char	*jump_print(char *str, t_utils *utils);
bool	set_flags(t_utils *utils, char *str, ssize_t *i);
bool	specifiers(t_utils *utils, char flag);
bool	_null_handler(t_utils *utils, char flag);
bool	clear_args(t_utils *utils, va_list *copy);
bool	_padding(t_utils *utils);
bool	flush_buffer(t_utils *utils);

#endif
