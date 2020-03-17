#include "tlpi_hdr.h"

int main() {
    pid_t ppid, orig;
    setbuf(stdout, NULL);     
    orig = getpid();

    switch (fork()) {
    case -1:
        printf("fork");

    case 0:             
        while ((ppid = getppid()) == orig) {   
            printf("Child is running (Parent's PID is %ld)\n", (long) ppid);
            sleep(1);
        }
        printf("Child is orphaned (Parent's PID is %ld now - as expected)\n", (long) ppid);
        _exit(EXIT_SUCCESS);

    default:           
        printf("Parent (PID of %ld) is going to sleep. \n", (long) getpid());
        sleep(5);                          
        printf("Parent has exited.\n");
        exit(EXIT_SUCCESS);
    }
}