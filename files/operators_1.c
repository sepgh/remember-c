#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int a = 5;
    // 5 =   0101
    // 10 =  1010
    // 20 = 10100
    // 4 =   0100
    int i;
    for (i = 0; i < 32; i++) {
        printf("Left shifted by %02d: %08x | %d\n", i, a << i, a << i);
    }
    for (i = 0; i < 32; i++) {
        printf("Right shifted by %02d: %08x | %d\n", i, a >> i, a >> i);
    }
    return 0;
}