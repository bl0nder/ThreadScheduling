#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

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
        char copy1[100];
        strcpy(cop1, "cp linux-6.0.9.tar kernel1/linux-6.0.9.tar");
        //test
        execlp("mkdir", "mkdir", "kernel1", NULL);
        // execlp("sh", "sh", "-c", "cp linux-6.0.9.tar kernel1/linux-6.0.9.tar");
        // execl("cp", "cp", "/home/bl0nder/threadScheduling/ThreadScheduling/linux-6.0.9.tar", "/home/bl0nder/threadScheduling/ThreadScheduling/kernel1/linux-6.0.9.tar", NULL);
        system(copy1);
        chdir("kernel1");
        execlp("tar", "tar", "-xvf", "linux-6.0.9.tar", NULL);
        chdir("linux-6.0.9");
        execlp("make", "make", "mrproper", NULL);
        execl("cp", "cp", "../../config-rev-9-gold", "./kernel1/linux-6.0.9/.config", NULL);
        // execlp("make", "make", NULL);

        return 0;
    }

    else {

        // pid_t p2;
        // p2 = fork();

        // if (p2 < 0) {
        //     perror("Error executing fork(): ");
        //     return -1;
        // }
        // else if (p2 == 0) {
        //     execlp("mkdir", "mkdir", "kernel2", NULL);
        //     execlp("cp", "cp", "./linux-6.0.9.tar", "kernel2/linux-6.0.9.tar", NULL);
        //     chdir("kernel2");
        //     execlp("tar", "tar", "-xvf", "linux-6.0.9.tar", NULL);
        //     chdir("linux-6.0.9");
        //     execlp("make", "make", "mrproper", NULL);
        //     execlp("cp", "cp", "../../config-rev-9-gold", "./kernel2/linux-6.0.9/.config", NULL);
        //     execlp("make", "make", NULL);
        //     return 0;
        // }



        int startTime = clock_gettime(CLOCK_REALTIME, &start);
        wait(NULL);
        int endTime = clock_gettime(CLOCK_REALTIME, &end);

        double runTime = (end.tv_sec + 1.0e-9*end.tv_nsec - (start.tv_sec + 1.0e-9*start.tv_nsec));

        printf("Runtime of Process 1 = %lfs\n", runTime);
    }

    

    return 0;
}