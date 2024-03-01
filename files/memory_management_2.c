#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Example {
    int x; // 4 bytes
    char y; // 1 byte
    // 3 bytes pad
    int z; // 4 bytes
} Example;

typedef struct Example2 {
    long long x;
    Example e;
} Example2;

int main(int argc, char* argv[]) {
    Example t;
    printf("Size: %llu\n", sizeof(t));
    printf("Offset of 'e' within Example2 is %llu\n", offsetof(Example2, e));
    return 0;
}