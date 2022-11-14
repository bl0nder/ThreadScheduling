#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sched.h>
#include <sys/types.h>

int main() {
    //Creating three processes
    pid_t p1;
    
    p1 = fork();

    if (p1 < 0) {
        perror("Error executing fork(): ");
        return -1;
    }

    else if (pid == 0) {
        execl();
    }

    pid_t p2;
    pid_t p3;

    

    return 0;
}
