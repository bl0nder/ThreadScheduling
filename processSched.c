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
        param2 -> sched_priority = 1;
    }
    if (param3 != NULL) {
        param3 -> sched_priority = 1;
    }

    int count = 1000000000;
    pid_t p1;
    pid_t p2;
    pid_t p3;
    int startTime1 = clock_gettime(CLOCK_REALTIME, &start1);
    int startTime2 = clock_gettime(CLOCK_REALTIME, &start2);
    int startTime3 = clock_gettime(CLOCK_REALTIME, &start3);
    // p1 = fork();

    if ((p1 = fork()) == 0) {
        // nice(-10);
        sched_setscheduler(p1, SCHED_OTHER, param1);
        printf("Process 1 started\n");
        // for (int i=1; i<=count; i++) {
        //     continue;
        // }
        execlp("bash", "bash", "compileKernel1.sh", NULL);
        
    }

    else if ((p2 = fork()) == 0) {
        sched_setscheduler(p2, SCHED_RR, param2);
        // nice(5);
        printf("Process 2 started\n");
        // for (int i=1; i<=count; i++) {
        //     continue;
        // }
        execlp("bash", "bash", "compileKernel2.sh", NULL);
        
    }
    
    else if ((p3 = fork()) == 0) {
        // nice(1);
        sched_setscheduler(p3, SCHED_FIFO, param3);
        printf("Process 3 started\n");
        // for (int i=1; i<=count; i++) {
        //     continue;
        // }
        execlp("bash", "bash", "compileKernel3.sh", NULL);
        
    }

    FILE *file1;
    FILE *file2;
    FILE *file3;
    
    file1 = fopen("processRuntimeCFS.txt", "a");
    file2 = fopen("processRuntimeRR.txt", "a");
    file3 = fopen("processRuntimeFIFO.txt", "a");

    for (int i=0; i<3; i++) {
        pid_t pEnd = wait(NULL);
        if (pEnd == p1) {
            int endTime1 = clock_gettime(CLOCK_REALTIME, &end1);
            double runTime1 = (end1.tv_sec + 1.0e-9*end1.tv_nsec - (start1.tv_sec + 1.0e-9*start1.tv_nsec));
            fprintf(file1, "%d %lf\n", param1->sched_priority, runTime1);
        // return 0;
        }
        else if (pEnd == p2) {
            int endTime2 = clock_gettime(CLOCK_REALTIME, &end2);
            double runTime2 = (end2.tv_sec + 1.0e-9*end2.tv_nsec - (start2.tv_sec + 1.0e-9*start2.tv_nsec));
            fprintf(file2, "%d %lf\n", param2->sched_priority, runTime2);
            // return 0;
        }
        else if (pEnd == p3) {
            int endTime3 = clock_gettime(CLOCK_REALTIME, &end3);
            double runTime3 = (end3.tv_sec + 1.0e-9*end3.tv_nsec - (start3.tv_sec + 1.0e-9*start3.tv_nsec));
            fprintf(file3, "%d %lf\n", param3->sched_priority, runTime3);
            // return 0;
        }
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);
    // if (p1 > 0) {
    //     waitpid(p1,NULL,0);
    // }
    // if (p2 > 0) {
    //     waitpid(p2,NULL,0);
    // }
    // if (p3 > 0) {
    //     waitpid(p3, NULL, 0);
    // }
    printf("All processes have terminated.\n");
    return 0;
}