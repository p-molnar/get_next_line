#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
char	*get_next_line(int fd)
{
	static char	static_buf[BUFFER_SIZE + 1] = {0};
	char		*buf;
	int			read_status;
	char		*nl_ptr;

	nl_ptr = ft_strchr(static_buf, '\n');
	if (nl_ptr)
		return (return_line(static_buf, nl_ptr, static_buf, 's'));
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (free_buf(buf, 'd', 0, 1));
	read_status = read(fd, buf, BUFFER_SIZE);
	buf = ft_strjoin(static_buf, buf, "sd");
	if ((read_status == 0 && !buf[0]) || read_status == -1)
		return (free_buf(buf, 'd', 0, 1));
	nl_ptr = ft_strchr(buf, '\n');
	while (!nl_ptr)
	{
		read_status = read(fd, static_buf, BUFFER_SIZE);
		if (read_status == 0)
			return (return_line(buf, nl_ptr, static_buf, 'd'));
		buf = ft_strjoin(buf, static_buf, "ds");
		nl_ptr = ft_strchr(buf, '\n');
		if ((read_status == 0 && !buf[0]) || read_status == -1)
			return (free_buf(buf, 'd', 0, 1));
	}
	return (return_line(buf, nl_ptr, static_buf, 'd'));
}

char	*return_line(char *buf, char *nl_ptr, char *static_space, char mem_type)
{
	char	*line;

	line = ft_substr(buf, nl_ptr);
	if (nl_ptr && *(nl_ptr + 1))
		ft_strlcpy(static_space, nl_ptr + 1, BUFFER_SIZE + 1);
	else
		free_buf(static_space, 's', 1, 0);
	if (mem_type == 'd')
		free_buf(buf, 'd', 0, 0);
	return (line);
}

char	*free_buf(char *buf, char mem_type, int reset_buf, int return_null)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && reset_buf)
		buf[i++] = '\0';
	if (mem_type == 'd')
		free(buf);
	if (return_null)
		return (NULL);
	return ("");
}
