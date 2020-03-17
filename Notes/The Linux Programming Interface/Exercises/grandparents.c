#include "tlpi_hdr.h"

int main() {
    pid_t cpid, ppid, grandpid;
    setbuf(stdout, NULL);     
    grandpid = getpid();
    printf("Grandparent process is running (PID is %ld)\n", (long) grandpid);
    switch (fork()) {
    case -1:
        printf("fork");

    case 0:             
       if ((ppid = getppid() == grandpid)) {   
            printf("Child is running (Parent's PID is %ld)\n", (long) ppid);
             cpid = fork();      
            printf ("I'm the grandchild with PID %d and PPID %d.\n", getpid (), getppid ()); 
        } else {
            printf("Child is orphaned (Parent's PID is %ld now - as expected)\n", (long) ppid);
            _exit(EXIT_SUCCESS);
        }
    //
    default:           
        printf("Grandparent (PID of %ld) is going to sleep. \n", (long) getpid());
        printf("Grandparent has exited.\n");
        exit(EXIT_SUCCESS);
    }
}