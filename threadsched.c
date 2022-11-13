#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void countA() {
    struct timespec* start, end;
    int startTime = clock_gettime(CLOCK_REALTIME, start);
    for (unsigned long i=1; i<=5000; i++) {
        printf("%d ", i);
    }
    printf("\n");
    int endTime = clock_gettime(CLOCK_REALTIME, end);
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
