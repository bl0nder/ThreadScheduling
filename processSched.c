#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    //Creating three processes
    pid_t p1;
    struct timespec start;
    struct timespec end;

    p1 = fork();

    if (p1 < 0) {
        perror("Error executing fork(): ");
        return -1;
    }

    else if (p1 == 0) {
        execlp("echo", "echo", "bhai kya kuch ho bhi raha hai", NULL);
        // execlp("make", "Makefile", NULL);

        return 0;
    }

    else {

        int startTime = clock_gettime(CLOCK_REALTIME, &start);
        wait(NULL);
        int endTime = clock_gettime(CLOCK_REALTIME, &end);

        double runTime = (end.tv_sec + 1.0e-9*end.tv_nsec - (start.tv_sec + 1.0e-9*start.tv_nsec));

        printf("Runtime of Process 1 = %lfs\n", runTime);
    }

    pid_t p2;
    pid_t p3;

    

    return 0;
}
