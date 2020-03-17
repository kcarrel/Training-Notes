#include <ctype.h>
#include "tlpi_hdr.h"

#define BUF_SIZE 100    

int main() {
    char buf[BUF_SIZE];
    int outbound[2];            
    int inbound[2];             
    int j;
    ssize_t count;

    if (pipe(outbound) == -1)
        printf("pipe");
    if (pipe(inbound) == -1)
        printf("pipe");

    switch (fork()) {
    case -1:
        printf("fork");

    case 0:
        while ((count = read(outbound[0], buf, BUF_SIZE)) > 0) {
            for (j = 0; j < count; j++)
                buf[j] = toupper((unsigned char) buf[j]);
            if (write(inbound[1], buf, count) != count)
                printf("Failed to write from the inbound pipe");
        }
    default:
        while ((count = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
            if (write(outbound[1], buf, count) != count)
                printf("Failed to write from the outbound pipe");
            count = read(inbound[0], buf, BUF_SIZE);
            if (count == -1)
                printf("read");
            if (count > 0)
                if (write(STDOUT_FILENO, buf, count) != count)
                    printf("Failed to write because STDOUT_FILENO");
        }
        
        exit(EXIT_SUCCESS);
    }
}