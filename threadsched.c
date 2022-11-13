#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void countA() {
    for (unsigned long i=1; i<=4294967296; i++) {
        continue;
    }
}

void* Thr_A() {
    struct timespec start;
    struct timespec end;
    printf("Counting starts now!\n");
    
    int startTime = clock_gettime(CLOCK_REALTIME, &start);
    countA();
    int endTime = clock_gettime(CLOCK_REALTIME, &end);

    double runTime = (end.tv_sec + 1.0e-9*end.tv_nsec - (start.tv_sec + 1.0e-9*start.tv_nsec));

    printf("Runtime of CountA = %lfs\n", runTime);
}

void countB() {
    struct timespec start;
    struct timespec end;
    printf("Counting starts now!\n");
    
    int startTime = clock_gettime(CLOCK_REALTIME, &start);
    for (unsigned long i=1; i<=4294967296; i++) {
        continue;
    }
    int endTime = clock_gettime(CLOCK_REALTIME, &end);

    double runTime = (end.tv_sec + 1.0e-9*end.tv_nsec - (start.tv_sec + 1.0e-9*start.tv_nsec));
    // long double runTimeNSec = end.tv_nsec - start.tv_nsec;

    printf("Runtime of CountB = %lfs\n", runTime);
}

void countC() {
    struct timespec start;
    struct timespec end;
    printf("Counting starts now!\n");
    
    int startTime = clock_gettime(CLOCK_REALTIME, &start);
    for (unsigned long i=1; i<=4294967296; i++) {
        continue;
    }
    int endTime = clock_gettime(CLOCK_REALTIME, &end);

    double runTime = (end.tv_sec + 1.0e-9*end.tv_nsec - (start.tv_sec + 1.0e-9*start.tv_nsec));
    // long double runTimeNSec = end.tv_nsec - start.tv_nsec;

    printf("Runtime of CountC = %lfs\n", runTime);
}

int main() {
    
    pthread_t ThrA;
    pthread_t ThrB;
    pthread_t ThrC;

    int t1 = pthread_create(ThrA, NULL, Thr_A, NULL);
    pthread_join(t1, NULL);

    return 0;
}
