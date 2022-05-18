/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 09:51:55 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/18 15:24:10 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>

char	*get_next_line(int fd);

void	*gnl_calloc(size_t count, size_t size);
char	*gnl_substr(char *start, char *end, char mem_type);
char	*gnl_strjoin(char *s1, char *s2, char *mem_type);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);

char	*return_line(char *buf, char *nl_ptr, char *perm_space, char mem_type);
char	*free_buf(char *buf, char mem_type, int reset_buf, int return_null);
char	*read_further(char *nl_ptr, int fd, char *perm_buf, char *buf);
#endif