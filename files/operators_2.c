#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_FLAG 0b1
#define SECOND_FLAG 0b10
#define THIRD_FLAG 0b10000000

int main(int argc, char* argv[]) {
    unsigned int flags = FIRST_FLAG | SECOND_FLAG | THIRD_FLAG;
    
    flags = flags & ~SECOND_FLAG;
    flags = flags | SECOND_FLAG;
    
    if (flags & FIRST_FLAG) {
        printf("First flag is enabled\n");
    }
    if (flags & SECOND_FLAG) {
        printf("Second flag is enabled\n");
    }
    if (flags & THIRD_FLAG) {
        printf("Third flag is enabled\n");
    }
    
    return 0;
}