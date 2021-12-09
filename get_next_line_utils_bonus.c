/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 09:52:00 by pmolnar       #+#    #+#                 */
/*   Updated: 2021/12/09 16:26:17 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*space;
	int		i;

	i = 0;
	space = malloc(size * count);
	if (!space)
		return (NULL);
	while ((unsigned long)i < (size * count))
		space[i++] = '\0';
	return ((void *)space);
}

char	*ft_substr(char *start, char *end, char mem_type)
{
	int		i;
	int		substr_len;
	char	*substr;

	i = 0;
	if (end)
		substr_len = end - start + 1;
	else
		substr_len = ft_strchr(start, '\0') - start + 1;
	substr = ft_calloc(substr_len + 1, sizeof(char));
	if (!substr)
		return (free_buf(start, mem_type, 0, 1));
	while (i < substr_len)
	{
		substr[i] = start[i];
		i++;
	}
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2, char *mem_type)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strchr(s1, '\0') - s1;
	s2_len = ft_strchr(s2, '\0') - s2;
	str = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!str)
	{
		free_buf(s1, mem_type[0], 1, 0);
		free_buf(s2, mem_type[1], 1, 0);
		return (NULL);
	}
	ft_strlcpy(ft_strchr(str, '\0'), s1, s1_len + 1);
	ft_strlcpy(ft_strchr(str, '\0'), s2, s2_len + 1);
	free_buf(s1, mem_type[0], 1, 0);
	free_buf(s2, mem_type[1], 1, 0);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*ptr_src;
	int		src_len;

	ptr_src = (char *)src;
	src_len = ft_strchr(src, '\0') - src;
	if (!dstsize)
		return (src_len);
	while (*ptr_src && (dstsize-- - 1))
		*dst++ = *(char *)ptr_src++;
	*dst = '\0';
	return (src_len);
}

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s && *s != (char)c)
			s++;
		if (*s == (char)(c))
			return ((char *)s);
	}
	return (NULL);
}
