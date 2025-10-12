/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:07:29 by ellabiad          #+#    #+#             */
/*   Updated: 2025/10/11 16:03:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 5
#endif
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*fill_stash(char *buffer, char *stash, int fd);
char	*fill_line(char **stash);
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(char *str, char c);
char	*gnl_strdup(char *str);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strjoin(char *s1, char *s2);

#endif