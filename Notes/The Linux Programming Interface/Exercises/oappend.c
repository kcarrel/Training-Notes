#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define STRING "Hi, this is a string!"

int main(int argc, char *argv[]) {
    int fd;

    if (argc != 2) {
        printf("Specify a file (arg 1) \n");
        return 1;
    }
    fd = open(argv[1], O_RDWR | O_APPEND);
    lseek(fd, 0, SEEK_SET);
    write(fd, STRING, sizeof(STRING));
    close(fd);
    return 0;
}