#include <stdio.h>

void countA() {
    for (unsigned long i=1; i<4294967296; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    printf("Hello world\n");
    return 0;
}
