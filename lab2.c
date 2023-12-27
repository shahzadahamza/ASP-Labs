#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    umask(0); // Set umask to 0 to ensure all permissions are granted

    // Check if the file already exists
    if (access("new.txt", F_OK) != -1) {
        printf("File 'new.txt' Exists.\n");
        return 1;
    }

    int fd1 = open("new.txt", O_CREAT | O_WRONLY, 0766);

    if (fd1 == -1) {
        perror("Error while creating the file");
        return 1;
    }

    const char* message = "Welcome to COMP 8567";
    if (write(fd1, message, strlen(message)) == -1) {
        perror("Error while writing to the file");
        close(fd1);
        return 1;
    }

    printf("File 'new.txt' created successfully!\n");
//    print("File new.txt written successfully!\n");
    close(fd1);

    int fd2 = open("new.txt", O_WRONLY | O_APPEND);
    if (fd2 == -1) {
        perror("Error while opening the file in O_APPEND mode");
        return 1;
    }

    const char* line2 = "Advanced Systems Programming";
    const char* line3 = "University of Windsor";

    if (write(fd2, "\n", 1) == -1) {
        perror("Error while appending line2");
        close(fd2);
        return 1;
    }
    if (write(fd2, line2, strlen(line2)) == -1) {
        perror("Error while appending line2");
        close(fd2);
        return 1;
    }

    if (write(fd2, "\n", 1) == -1) {
        perror("Error while appending line3");
        close(fd2);
        return 1;
    }
    if (write(fd2, line3, strlen(line3)) == -1) {
        perror("Error while appending line3");
        close(fd2);
        return 1;
    }

    printf("Appended to 'new.txt' successfull!\n");
    close(fd2);

    int fd3 = open("new.txt", O_RDWR);
    if (fd3 == -1) {
        perror("Error while opening the file in O_RDWR mode");
        return 1;
    }

    lseek(fd3, 10, SEEK_SET); //10 bytes from the beginning of the file
    write(fd3, "####&&&&", 8);

    lseek(fd3, 12, SEEK_CUR);//12 bytes after the previous operation is performed
    write(fd3, "####&&&&", 8);

    lseek(fd3, 40, SEEK_END);//40 bytes after the end of the file
    write(fd3, "####&&&&", 8);

    lseek(fd3, 0, SEEK_SET);
    char buffer[1];
    while (read(fd3, buffer, 1) == 1) {
        if (buffer[0] == '\0') {
            lseek(fd3, -1, SEEK_CUR);
            write(fd3, "N", 1);
        }//Replace all the NULL characters in the file with the ‘N’ character
    }

    close(fd3);
    printf("File 'new.txt' modified successfully!\n");

    int fd4 = open("new.txt", O_RDONLY);
    if (fd4 == -1) {
        perror("Error while opening the file in O_RDONLY mode");
        return 1;
    }

    char line[11];
    printf("Contents of 'new.txt':\n");
    while (read(fd4, line, 10) > 0) {
        line[10] = '\0';
        printf("%s\n", line);
    }

    struct stat st;
    if (stat("new.txt", &st) == 0) {
        printf("File size: %ld bytes\n", st.st_size);
    }

    close(fd4);

    return 0;
}
