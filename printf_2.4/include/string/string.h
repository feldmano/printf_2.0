/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/18 11:20:57 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/02 23:35:12 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include <unistd.h> // for ssize_t, size_t

ssize_t		pf_strlen(char *str);
char		*pf_itoa(int sign);
char		*pf_utoa(unsigned int unsign);
char		*pf_strchr(const char *str, const char c);
char		base(unsigned int unsign, int flag);

#endif