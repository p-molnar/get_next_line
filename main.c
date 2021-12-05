// open prereq.
#include <fcntl.h>

#include "get_next_line.h"

#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    int i;

    fd = open("test_files/alternate_line_nl_no_nl.txt", O_RDONLY);
    line = get_next_line(fd);
    i = 0;
    // printf("-main start\n");
    while (line)
    {
        // printf("#%i: |%s|", i, line);
        printf("%s", line);
        line = get_next_line(fd);
        i++;
    }
    // printf("\n-main finished\n");
}