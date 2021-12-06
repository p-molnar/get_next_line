#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <limits.h>

char	*get_next_line(int fd)
{
	static char	static_buf[INT_MAX][BUFFER_SIZE + 1]; 
	char		*buf;
	int			read_status;
	char		*nl_ptr;

	nl_ptr = ft_strchr(static_buf[fd], '\n');
	if (nl_ptr)
		return (return_line(static_buf[fd], nl_ptr, static_buf[fd], 's'));
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (free_buf(buf, 'd', 0, 1));
	read_status = read(fd, buf, BUFFER_SIZE);
	buf = ft_strjoin(static_buf[fd], buf, "sd");
	if ((read_status == 0 && !buf[0]) || read_status == -1)
		return (free_buf(buf, 'd', 0, 1));
	nl_ptr = ft_strchr(buf, '\n');
	return (read_further(nl_ptr, fd, static_buf[fd], buf));
}

char    *read_further(char *nl_ptr, int fd, char *static_buf, char *buf)
{
    int read_status;

    while (!nl_ptr)
    {
        read_status = read(fd, &static_buf[fd], BUFFER_SIZE);
        if (read_status == 0)
            return (return_line(buf, nl_ptr, &static_buf[fd], 'd'));
        buf = ft_strjoin(buf, &static_buf[fd], "ds");
        nl_ptr = ft_strchr(buf, '\n');
        if (!buf[0] || read_status == -1)
            return (free_buf(buf, 'd', 0, 1));
    }
    return (return_line(buf, nl_ptr, &static_buf[fd], 'd'));
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