#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <libc.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Processus enfant
        char buffer[100];
        read(fd, buffer, 99); // Lit le fichier
        buffer[99] = '\0';
        printf("Child process read: %s\n", buffer);
    } else if (pid > 0) {
        // Processus parent
        printf("Parent process, file descriptor: %d\n", fd);
        wait(NULL); // Attend l'enfant
    } else {
        perror("Fork failed");
    }

    close(fd); // Ferme le fichier
    return 0;
}