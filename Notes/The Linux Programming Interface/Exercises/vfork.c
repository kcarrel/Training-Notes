#include <stdio.h>
#include <unistd.h>
#include "tlpi_hdr.h"

int main() {
    int childPid;
    childPid = vfork();
    switch(childPid) {
    case -1: 
        printf ("The child process has not been created.");
    case 0: 
        printf ("Am child, my Parent id: %d",getppid() );
        if (close(STDOUT_FILENO) == -1)
            printf("close - child");
        _exit(EXIT_SUCCESS);
    default: break;
    }
   if (close(STDOUT_FILENO) == -1)
        printf("close");
    if (close(STDOUT_FILENO) == -1)
        printf("close");
    exit(EXIT_SUCCESS);
}