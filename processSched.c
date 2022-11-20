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
    struct timespec start1;
    struct timespec end1;
    struct timespec start2;
    struct timespec end2;
    struct timespec start3;
    struct timespec end3;

    struct sched_param* param1 = (struct sched_param*)malloc(sizeof(struct sched_param));
    struct sched_param* param2 = (struct sched_param*)malloc(sizeof(struct sched_param));
    struct sched_param* param3 = (struct sched_param*)malloc(sizeof(struct sched_param));

    if (param1 != NULL) {
        param1 -> sched_priority = 0;
    }
    if (param2 != NULL) {
        param2 -> sched_priority = 0;
    }
    if (param3 != NULL) {
        param3 -> sched_priority = 0;
    }

    
    pid_t p1;
    int startTime1 = clock_gettime(CLOCK_REALTIME, &start1);
    p1 = fork();
    sched_setscheduler(p1, SCHED_OTHER, param1);
    if (p1 < 0) {
        perror("Error executing fork(): ");
        return -1;
    }

    else if (p1 == 0) {
        // char copy1[100];
        // strcpy(copy1, "cp linux-6.0.9.tar kernel1/linux-6.0.9.tar");
        //test
        // execlp("mkdir", "mkdir", "kernel1", NULL);
        // chdir("kernel1");
        // // system("wget 'https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.19.9.tar.xz'");
        // execl("/bin/wget", "https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.19.9.tar.xz", NULL);
        // execlp("unxz", "unxz", "linux-5.19.9.tar.xz", NULL);
        // execlp("tar", "tar", "-xvf", "linux-5.19.9.tar", NULL);
        // chdir("linux-5.19.9");
        // execlp("make", "make", "mrproper", NULL);
        // execlp("wget", "wget", "-O", ".config", "https://github.com/bl0nder/ThreadScheduling/blob/405cc153b9dc8fd333485780413fb1de3d3b7e09/config-rev-9-gold", NULL);
        // execlp("make", "make", NULL);
        execlp("bash", "bash", "compileKernel1.sh", NULL);
        return 0;
    }

    else {
        pid_t p2;
        int startTime2 = clock_gettime(CLOCK_REALTIME, &start2);
        p2 = fork();
        sched_setscheduler(p2, SCHED_RR, param2);

        if (p2 < 0) {
            perror("Error executing fork(): ");
            return -1;
        }
        else if (p2 == 0) {
            execlp("bash", "bash", "compileKernel2.sh", NULL);
            return 0;
        }
        else {
            pid_t p3;
            int startTime3 = clock_gettime(CLOCK_REALTIME, &start3);
            p3 = fork();
            sched_setscheduler(p3, SCHED_FIFO, param3);

            if (p3 < 0) {
                perror("Error executing fork(): ");
                return -1;
            }
            else if (p3 == 0) {
                execlp("bash", "bash", "compileKernel3.sh", NULL);
                return 0;
            }
            else {
                waitpid(p3, NULL, 0);
                int endTime3 = clock_gettime(CLOCK_REALTIME, &end3);

                double runTime3 = (end3.tv_sec + 1.0e-9*end3.tv_nsec - (start3.tv_sec + 1.0e-9*start3.tv_nsec));

                printf("Runtime of Process 3 = %lfs\n", runTime3);
            }

            waitpid(p2, NULL, 0);
            int endTime2 = clock_gettime(CLOCK_REALTIME, &end2);

            double runTime2 = (end2.tv_sec + 1.0e-9*end2.tv_nsec - (start2.tv_sec + 1.0e-9*start2.tv_nsec));

            printf("Runtime of Process 2 = %lfs\n", runTime2);
        }

        waitpid(p1, NULL, 0);
        int endTime1 = clock_gettime(CLOCK_REALTIME, &end1);

        double runTime1 = (end1.tv_sec + 1.0e-9*end1.tv_nsec - (start1.tv_sec + 1.0e-9*start1.tv_nsec));

        printf("Runtime of Process 1 = %lfs\n", runTime1);
    }

    

    return 0;
}