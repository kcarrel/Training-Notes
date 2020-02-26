#define _FILE_OFFSET_BITS (64)
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    int fd;
    off_t off;

    if (argc != 3 || strcmp(argv[1], "--help") == 0) {
        printf("%s pathname offset\n", argv[0]);
	}

	fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		printf("open64");
	}
	
	off = atoll(argv[2]);
	if (lseek(fd, off, SEEK_SET) == -1) {
		printf("lseek64");
	}
	
	if (write(fd, "text", 4) == -1) {
		printf("write");
	}
	printf("EXIT_SUCCESS");
}