#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int i;
    int** arr = malloc(sizeof(int*) * 3);
    for (i = 0; i < 3; i++) {
        arr[i] = malloc(sizeof(int) * 3);
    }
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;
    arr[2][0] = 7;
    arr[2][1] = 8;
    arr[2][2] = 9;
    
    printf("Size is %llu\n", sizeof(arr) + size(arr[0]) * 3 + sizeof(int) * 3 * 3);
    
    // Deallocation
    for (i = 0; i < 3; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;

    return 0;
}