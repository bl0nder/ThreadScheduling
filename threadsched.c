#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void countA() {
    for (unsigned long i=1; i<5000; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void countB() {
    for (unsigned long i=1; i<4294967296; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void countC() {
    for (unsigned long i=1; i<4294967296; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    
    pthread_t Thr-A;
    pthread_t Thr-B;
    pthread_t Thr-C;

    countA();

    return 0;
}
