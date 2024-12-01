/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ompelman <ompelman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/01 10:58:17 by ompelman      #+#    #+#                 */
/*   Updated: 2024/12/01 15:15:49 by ompelman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
# include <stdlib.h>

void		*pf_calloc(size_t mems, size_t size);
char		*pf_strjoin(const char *str, const char *str2);

#endif