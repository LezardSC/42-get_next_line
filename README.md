# get_next_line

## Overview

**get_next_line** is a 42 School project that is designed to create a function that reads text from a file descriptor one line at a time. Its primary goal is to mimic the behavior of the standard input functions by returning one line with each call. The function must handle dynamic memory allocation, work with a defined buffer size (defaulted to 20 if not specified), and correctly process newlines. In the bonus part of the project, the implementation is extended to support multiple file descriptors simultaneously.

This project challenges you to manage file I/O, buffer manipulation, and memory management in C, reinforcing the fundamentals of reading files and handling strings.


## Testing with Bible.txt
A sample text file (`Bible.txt`) is provided for testing purposes. You can use this file to verify that your get_next_line function correctly reads and returns each line from a file. Here’s a simple test scenario:

- Compile your code, making sure to link all required source files and define BUFFER_SIZE if needed.

- Write a main program to open the file, call get_next_line in a loop, print each line, and free the allocated memory:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd = open("Bible.txt", O_RDONLY);
    char *line;

    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```
Run the program and check that it prints each line of the file as expected.


#### Author

login: jrenault
