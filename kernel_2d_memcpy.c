#include <stdlib.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0 (kernel_2d_memcpy) {
    int matrix[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};
    int tmp[5][5];
    int matrixCopy[5][5];

    copy_from_user((void *) &tmp, (const void*) &matrix, 25*sizeof(int));
    copy_to_user((void *) &matrixCopy, (const void*) &tmp, 25*sizeof(int));

    return 0;
}