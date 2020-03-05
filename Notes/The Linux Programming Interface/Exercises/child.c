#include "tlpi_hdr.h"

int main() {
    pid_t ppid, ppidOrig;
    setbuf(stdout, NULL);       
    ppidOrig = getpid();
    switch (fork()) {
    case -1:
        printf("fork");

    case 0:            
        while ((ppid = getppid()) == ppidOrig) {   
            printf("Child is running (parent PID=%ld)\n", (long) ppid);
            sleep(1);
        }
        printf("Child is orphaned (parent PID=%ld)\n", (long) ppid);
        _exit(EXIT_SUCCESS);

    default:            
        printf("Parent (PID=%ld) is sleeping\n", (long) getpid());
        sleep(3);                           
        printf("Parent is exiting\n");
        exit(EXIT_SUCCESS);
    }
}