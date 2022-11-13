#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void countA() {
    struct timespec start;
    struct timespec end;
    int startTime = clock_gettime(CLOCK_REALTIME, &start);
    for (unsigned long i=1; i<=10000; i++) {
        printf("%d ", i);
    }
    printf("\n");
    int endTime = clock_gettime(CLOCK_REALTIME, &end);

    long double runTimeSec = (end.tv_sec + (end.tv_nsec/1000000000) - start.tv_sec - (start.tv_nsec/1000000000));
    // long double runTimeNSec = end.tv_nsec - start.tv_nsec;

    printf("Runtime of CountA = %.10lfs\n", runTimeSec);
}

void countB() {
    for (unsigned long i=1; i<=4294967296; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void countC() {
    for (unsigned long i=1; i<=4294967296; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    
    pthread_t ThrA;
    pthread_t ThrB;
    pthread_t ThrC;

    countA();

    return 0;
}
