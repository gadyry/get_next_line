#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDWR); // Ouvre le fichier en lecture/écriture
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Écrit dans le fichier
    write(fd, "Hello, World!\n", 14);

    // Déplace l'offset au début du fichier
    lseek(fd, 0, SEEK_SET);

    // Lit depuis le fichier
    char buffer[15];
    read(fd, buffer, 14);
    buffer[14] = '\0'; // Ajoute un caractère nul pour terminer la chaîne

    printf("Data read from file: %s", buffer);

    // Ferme le file descriptor
    close(fd);
    return 0;
}