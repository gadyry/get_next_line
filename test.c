#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDONLY); // Ouvre un fichier en lecture seule
    if (fd < 0) {
        perror("Error opening file");
        return 1; // Erreur
    }

    printf("File descriptor: %d\n", fd); // Affiche le FD (par exemple : 3)
    
    close(fd); // Ferme le fichier
    return 0;
}