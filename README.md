# get_next_line (C getline reimplementation)

## Introduction
This repository contains a reimplementation of the [`getline()`](https://man7.org/linux/man-pages/man3/getline.3.html) function, which reads a line from a specified file descriptor.

The key difference between this function and the standard `getline()` is that `get_next_line` allows you to define a `BUFFER_SIZE` compiler flag. This flag determines the maximum amount of data read each time the function is called.

## Features
**Mandatory part:**
- Returns a line from a file descriptor.
- Reads up to `BUFFER_SIZE` data from a specified file descriptor.

**Bonus part:**
- In addition to the mandatory features, the bonus part enables reading from multiple file descriptors simultaneously, ensuring that the input reads from different file descriptors do not interfere with each other.

## Getting Started

To begin using this project, clone the repository into your project's root directory:

```bash
git clone https://github.com/p-molnar/get_next_line.git
```

## Usage

### For the mandatory `get_next_line()`

Below is an example illustrating how to integrate `get_next_line()` into your projects by including the necessary headers and source files:

1. After cloning the repository, your project directory structure should resemble the following:

```bash
project
├── a.out
├── get_next_line
│   ├── get_next_line.c
│   ├── get_next_line.h
│   ├── get_next_line_bonus.c
│   ├── get_next_line_bonus.h
│   ├── get_next_line_project_description.pdf
│   ├── get_next_line_utils.c
│   └── get_next_line_utils_bonus.c
├── input_1.txt
├── input_2.txt
└── main.c

```

2. To utilize `get_next_line()` in your code, include the `get_next_line.h` header and invoke the function in a loop to read from a specified file descriptor.

```c
#include <get_next_line.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int line_count = 1;
    int fd = open("input_1.txt", O_RDONLY);
    char *line = get_next_line(fd);
    while(line)
    {
        printf("line %d: %s", line_count, line);
        free(line);
        line = get_next_line(fd);
        line_count++;
    }
    close(fd);
    return EXIT_SUCCESS;    
}
```

3. To compile `get_next_line` into your project, use the following command, specifying the desired read size by defining `BUFFER_SIZE`, e.g., 256 bytes:

```bash
gcc -Wall -Wextra -Werror -I get_next_line -D BUFFER_SIZE=256 main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
```

### For the bonus `get_next_line()` to read from multiple file descriptors:

1. Update your `main()` function to open multiple files:

```c
#include <get_next_line.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 2

int main(void)
{
    int fds[SIZE] = {
        open("input_1.txt", O_RDONLY),
        open("input_2.txt", O_RDONLY),
    };

    char *lines[SIZE] = {
        get_next_line(fds[0]),
        get_next_line(fds[1]),
    };

    while(lines[0] || lines[1])
    {
        printf("%s", lines[0]);
        printf("%s", lines[1]);

        if (lines[0])
            free(lines[0]);
        if (lines[1])
            free(lines[1]);

        lines[0] = get_next_line(fds[0]);
        lines[1] = get_next_line(fds[1]);
    }
    close(fds[0]);
    close(fds[1]);
    return EXIT_SUCCESS;    
}
```

2. To compile `get_next_line` with the bonus functionality, follow the same compilation process as before, but include the bonus source files and define `BUFFER_SIZE`, e.g., 256 bytes:

```bash
gcc -Wall -Wextra -Werror -I get_next_line -D BUFFER_SIZE=256 main.c get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c 
```

## License

This project is licensed under the [MIT License](LICENSE), allowing you to use, modify, and distribute the code freely.

Feel free to reach out if you have any questions or feedback.
