# get_next_line (C getline reimplementation)

## Introduction
This repository contains the reimplementation of [`getline()`](https://man7.org/linux/man-pages/man3/getline.3.html) function that returns a line read from a defined file descriptor.

The way this function differs from the standard `getline()` is that `get_next_line` takes a compiler flag to define a `BUFFER_SIZE`, which defines the maximum read size each time the function is called.

## Features
Mandatory part:
- returns line from file descriptor
- read up to `BUFFER_SIZE` of data from a defined file descriptor

Bonus part:
- on top of the mandatory part, the bonus is able to read from multiple file descriptors at the same time

## Getting Started

To get started with this project, clone the repository into the root of your project directory:

```bash
git clone https://github.com/p-molnar/get_next_line.git
```

## Usage

### For the mandatory `get_next_line()`

The example below shows how you can include the `get_next_line()` into your own projects by including the `get_next_line`'s headers and source files:
1. The directory structure your `project` may look as follows after cloning the repo.

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

2. To include `get_next_line()` into your file, include `get_next_line.h` header, and call `get_next_line()` in a loop to read from a given file descriptor.
   
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

3. To compile `get_next_line` into your project, you need to do it as follows, and define `n` for read size.
```bash
gcc -Wall -Wextra -Werror -I get_next_line -D BUFFER_SIZE=<n> main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
```
For example
```bash
gcc -Wall -Wextra -Werror -I get_next_line -D BUFFER_SIZE=256 main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
```

### For the bonus `get_next_line()` to read from multiple file descriptors:

1. Update your `main()` to open multiple files:
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

2. To compile `get_next_line` into your project, you need to do it as follows, and define `n` for read size.
```bash
gcc -Wall -Wextra -Werror -I get_next_line -D BUFFER_SIZE=<n> main.c get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c 
```

## License

This project is licensed under the [MIT License](LICENSE), allowing you to use, modify, and distribute the code freely.

Feel free to reach out if you have any questions or feedback.
