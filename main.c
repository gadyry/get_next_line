#include <libc.h>
#include "get_next_line.h"


void    f()
{
    system("leaks a.out");
}

int main()
{
    atexit(f);
    int fd = open("test", O_RDONLY);

    if (fd < 0)
        return (write(2, "error\n", 6), 1);
    char *line;

    line = get_next_line(fd);
    while (line)
    {
        printf("%s\n",line);
        free(line);
        line = get_next_line(fd);
    }
}