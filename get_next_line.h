#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>

char	*get_next_line(int fd);

void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char *start, char *end);
char	*ft_strjoin(char *s1, char *s2, char *mem_type);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*return_line(char *buf, char *nl_ptr, char *perm_space, char mem_type);
char	*free_buf(char *buf, char mem_type, int reset_buf, int return_null);
char	*read_further(char *nl_ptr, int fd, char *static_buf, char *buf);
#endif