#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char    *get_next_line(int fd);

// get_next_line_utils.c
void	*ft_calloc(size_t count, size_t size);
char    *ft_substr(char *start, char *end);
char    *ft_strjoin(char *s1 ,char *s2, char *mem_type);
// strchr
// memmove


// get_next_line.c
char	*return_line(char *buf, char *nl_ptr, char *static_space);
char	*free_buf(char *buf, int return_null, char mem_type);