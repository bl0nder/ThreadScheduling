#include <stdlib.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <unistd.h>

int main () {
    // int matrix[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};
    // int matrixCopy[5][5];

    int matrix = 50;
    int matrixCopy;

    copy_from_user((void *) &matrixCopy, (const void*) &matrix, 1*sizeof(int));

    printf("matrixCopy: %d\n", matrixCopy);
    return 0;
}