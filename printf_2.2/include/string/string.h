/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/18 11:20:57 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 11:05:49 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include <unistd.h> // for ssize_t, size_t

char		*pf_strchr(const char *str, const char c);

char		*itoa(int n);
char		*utoa(unsigned int unsig);
char		get_base(unsigned int unsig, int flag);
ssize_t		pf_strlen(char *str);

#endif