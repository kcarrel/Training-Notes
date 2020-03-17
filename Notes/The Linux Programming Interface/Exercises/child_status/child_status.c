#include <sys/wait.h>
#include <signal.h>
#include "print_wait_status.h"          /* Declares printWaitStatus() */
#include "tlpi_hdr.h"

void printStatus(int code, int status) {
    if (code == CLD_EXITED) {
        printf("Child has exited with a status: %d\n", status);
    } else if (code == CLD_KILLED) {
        printf("Child was killed by the signal: %d (%s)\n", status, strsignal(status));
    } else if (code == CLD_STOPPED) {
        printf("Child was stopped by the signal: %d (%s)\n", status, strsignal(status));
    } else if (code == CLD_CONTINUED) {
        printf("Child continued. \n");
    } else {
        printf("Unexpected: Child has a status: (status=%x)\n", (unsigned int)status);
    }
}

int main(int argc, char *argv[]) {
    int status;
    pid_t childPid;

    if (argc > 1 && strcmp(argv[1], "--help") == 0)
        usageErr("%s [exit-status]\n", argv[0]);

    switch (fork()) {
    case -1: printf("fork");

    case 0:             /* Child: either exits immediately with given
                           status or loops waiting for signals */
        printf("Child started with PID = %ld\n", (long) getpid());
        if (argc > 1)                   /* Status supplied on command line? */
            exit(getInt(argv[1], 0, "exit-status"));
        else                            /* Otherwise, wait for signals */
            for (;;)
                pause();
        exit(EXIT_FAILURE);             /* Not reached, but good practice */

    default:            /* Parent: repeatedly wait on child until it
                           either exits or is terminated by a signal */
        for (;;) {
            childPid = waitid(P_ALL, 0, &child, WEXITED | WSTOPPED | WCONTINUED);
            if (childPid == -1)
                printf("waitid");
            printf("waitid() returned: PID=%ld; status=0x%04x (%d,%d)\n",
                    (long) child.si_pid, child.si_status,
                    (unsigned int) child.si_status, child.si_status >> 8);
            printStatus(NULL, status);
        }
    }
}