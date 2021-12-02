#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "get_next_line.h"

#include <stdio.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
char    *get_next_line(int fd)
{
	// printf("--get_next_line\n");
	static char static_buf[BUFFER_SIZE + 1] = {0};
	char	buf[BUFFER_SIZE + 1];
	char    *tmp;
	int		read_status;
	char	*nl_ptr;
	read_status = read(fd, buf, BUFFER_SIZE);
	nl_ptr = strchr(buf, '\n');	
	return (return_line(buf, nl_ptr, static_buf));
}

char	*return_line(char *buf, char *nl_ptr, char *static_space)
{
	// printf("--return_line\n");
	char	*line;
	line = ft_substr(buf, nl_ptr);
	// printf("return_val: %s\n", line);
	if (nl_ptr && *(nl_ptr + 1))
	{
		// printf("memmove op\n");
		memmove(static_space, nl_ptr + 1, BUFFER_SIZE);
	}
	// printf("static_buf: |%s|\n", static_space);
	return (line);
}

char	*free_buf(char *buf, int return_null, char mem_type)
{
	int	i;

	i = 0;
	while (buf[i])
		buf[i++] = '\0';
	if (mem_type == 'd')
		free(buf);	
	if (return_null)
		return (NULL);
	return ("");
}