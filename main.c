#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main()
{
    int fd1, fd2, fd3;
    char *line1, *line2, *line3;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    { 
        printf("Error in opening file!\n");
        return (1);
    }

    while (1)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        line3 = get_next_line(fd3);

        if (!line1 && !line2 && !line3)
            break;

        if (line1)
        {
            printf("|%s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("|%s", line2);
            free(line2);
        }
        if (line3)
        {
            printf("|%s", line3);
            free(line3);
        }
    }

    // Fermeture des fichiers
    close(fd1);
    close(fd2);
    close(fd3);

    return (0);
}
