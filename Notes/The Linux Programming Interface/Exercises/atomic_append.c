#define _DEFAULT_SOURCE
#define _BSD_SOURCE

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int print_usage(char *argv[])
{
	printf("%s <filename> <num-bytes> [x]\n", argv[0]);
	printf("Where x is only checked for existence\n");
	return 0;
}

int main(int argc, char *argv[])
{
	int fd;
	int flags;
	int i;
	long num_bytes;
	char *filename;

	flags = (O_RDWR | O_CREAT);
	if (argc == 3) {
		flags |= (O_APPEND);
	}

	filename = argv[1];
	num_bytes = atol(argv[2]);
	fd = open(filename, flags, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		printf("Could not open specified filename (%s)\n", filename);
		print_usage(argv);
		return 1;
	}

	for (i = 0; i < num_bytes; i++) {
		if (argc == 3) {
			write(fd, "i", 1);
		} else {
			lseek(fd, 0, SEEK_END);
			write(fd, "i", 1);
		}
	}

	close(fd);
	return 0;
}