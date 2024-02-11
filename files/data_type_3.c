#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union Example {
    long long num;
    char bytes[8];
    float floats[2];
} Example;

int main(int argc, char* argv[]) {
    Example e;
    e.bytes[0] = 17;
    
    printf("%lld\n", e.num);
    
    for (int i = 0; i < 8; i++) {
        printf("%02hhx ", e.bytes[i]);
    }
    
    return 0;
}