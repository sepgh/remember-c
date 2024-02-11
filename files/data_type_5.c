#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    unsigned char n = 254;
    int i;
    for (i = 0; i < 10; i++) {
        printf("%hhd | %hhX\n", n, n);
        n++;
    }
    return 0;
}