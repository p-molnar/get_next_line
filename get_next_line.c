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
	char    *buf;
	int		read_status;
	char	*nl_ptr;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_status = read(fd, buf, BUFFER_SIZE);
	buf = ft_strjoin(static_buf, buf, "sd");
	if ((read_status == 0 && !buf[0]) || read_status == -1)
		return (free_buf(buf, 'd', 0, 1));
	nl_ptr = strchr(buf, '\n');
	while (!nl_ptr)
	{
		// printf("while\n");
		read_status = read(fd, static_buf, BUFFER_SIZE);
		buf = ft_strjoin(buf, static_buf, "ds");
		nl_ptr = strchr(buf, '\n');
		if ((read_status == 0 && !buf[0]) || read_status == -1)
			return (free_buf(buf, 'd', 0, 1));
		else if (read_status == 0)
			return(return_line(buf, nl_ptr, static_buf));
	}
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
	free_buf(buf, 'd', 0, 0);
	// printf("static_buf: |%s|\n", static_space);
	return (line);
}

char	*free_buf(char *buf, char mem_type, int reset_buf, int return_null)
{
	int	i;

	i = 0;
	while (buf[i] && reset_buf)
		buf[i++] = '\0';
	if (mem_type == 'd')
		free(buf);	
	if (return_null)
		return (NULL);
	return ("");
}