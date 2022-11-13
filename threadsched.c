#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// struct args {
// };

void countA() {
    for (unsigned long i=1; i<=4294967296; i++) {
        continue;
    }
}

void countB() {
    for (unsigned long i=1; i<=4294967296; i++) {
        continue;
    }
}

void countC() {
    for (unsigned long i=1; i<=4294967296; i++) {
        continue;
    }
}

void* Thr_A(void* args) {
    struct timespec start;
    struct timespec end;
    printf("Counting starts now!\n");
    
    int startTime = clock_gettime(CLOCK_REALTIME, &start);
    countA();
    int endTime = clock_gettime(CLOCK_REALTIME, &end);

    double runTime = (end.tv_sec + 1.0e-9*end.tv_nsec - (start.tv_sec + 1.0e-9*start.tv_nsec));

    printf("Runtime of CountA = %lfs\n", runTime);

    return NULL;
}

void* Thr_B(void* args) {
    struct timespec start;
    struct timespec end;
    printf("Counting starts now!\n");
    
    int startTime = clock_gettime(CLOCK_REALTIME, &start);
    countB();
    int endTime = clock_gettime(CLOCK_REALTIME, &end);

    double runTime = (end.tv_sec + 1.0e-9*end.tv_nsec - (start.tv_sec + 1.0e-9*start.tv_nsec));

    printf("Runtime of CountB = %lfs\n", runTime);

    return NULL;
}

void* Thr_C(void* args) {
    struct timespec start;
    struct timespec end;
    printf("Counting starts now!\n");
    
    int startTime = clock_gettime(CLOCK_REALTIME, &start);
    countC();
    int endTime = clock_gettime(CLOCK_REALTIME, &end);

    double runTime = (end.tv_sec + 1.0e-9*end.tv_nsec - (start.tv_sec + 1.0e-9*start.tv_nsec));

    printf("Runtime of CountC = %lfs\n", runTime);

    return NULL;
}

int main() {
    
    pthread_t ThrA;
    pthread_t ThrB;
    pthread_t ThrC;

    struct sched_param* paramA = (struct sched_param*)malloc(sizeof(struct sched_param));
    struct sched_param* paramB = (struct sched_param*)malloc(sizeof(struct sched_param));
    struct sched_param* paramC = (struct sched_param*)malloc(sizeof(struct sched_param));

    // Thread A
    pthread_setschedparam(ThrA, SCHED_OTHER, paramA);
    pthread_setschedparam(ThrB, SCHED_RR, paramB);
    // pthread_setschedparam(ThrC, SCHED_FIFO, paramC);

    //Thread B
    pthread_create(&ThrA, NULL, Thr_A, NULL);
    pthread_create(&ThrB, NULL, Thr_B, NULL);
    // pthread_create(&ThrC, NULL, Thr_C, NULL);

    //Thread C

    //Joining all threads
    pthread_join(ThrA, NULL);
    pthread_join(ThrB, NULL);
    // pthread_join(ThrC, NULL);
    
    //Free memory taken by parameters
    // free(paramA);
    // free(paramB);
    // free(paramC);

    return 0;
}
