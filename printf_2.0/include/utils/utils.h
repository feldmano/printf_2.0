/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/18 11:20:57 by ompelman      #+#    #+#                 */
/*   Updated: 2024/11/23 13:38:02 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <unistd.h> // for ssize_t, size_t

void		*pf_calloc(size_t mems, size_t size);
char		*pf_strjoin(const char *str, const char *str2);
char		*pf_strchr(const char *str, const char c);
int			llong_digitcounter(long long int num);
int			size_digitcounter(size_t size);
char		*itoa(int n);
char		*utoa(unsigned int unsig);
char		get_base(unsigned int unsig, int flag);

#endif