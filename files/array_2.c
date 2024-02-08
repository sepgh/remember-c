#include <stdio.h>
#include <stdlib.h>

void printSize(int* arrParam) {
   printf("Size of the array in function %llu\n", sizeof(arrParam));
   arrParam[2] = 10;
}

int main(int argc, char* argv[]) {
    int arr[5] = { 1, 2, 3, 4, 5 };
    printf("Size of the array in main %llu\n", sizeof(arr));
    printSize(arr); // arr -> int*
    printf("%d\n", arr[2]);
    return 0;
}

/*

// MULTI DIMENSIONAL

#include <stdio.h>
#include <stdlib.h>

void printSize(int* arrParam) {
   printf("Size of the array in function %llu\n", sizeof(arrParam));
   arrParam[2 * 5 + 2] = 10;
}

int main(int argc, char* argv[]) {
    int arr[5][5] = {
        { 1, 2, 3, 4, 5 },
        { 1, 2, 3, 4, 5 },
        { 1, 2, 3, 4, 5 },
        { 1, 2, 3, 4, 5 },
        { 1, 2, 3, 4, 5 }
    };
    printf("Size of the array in main %llu\n", sizeof(arr));
    printSize((int*) arr); // arr -> int (*)[5]
    printf("%d\n", arr[2][2]);
    return 0;
}

*/