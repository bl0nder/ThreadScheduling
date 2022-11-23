#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>


int main() {
    int sourceMatrix[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};
    int destMatrix[5][5] = {{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};

    int flag = syscall(451, sourceMatrix, destMatrix, 5, 5);

    if (!flag) {
        printf("Copy has been succesful. Here is the destination matrix:\n");
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                printf("%d ", destMatrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;

}