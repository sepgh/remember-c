#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATTERN "My name is "

const char* PATTERN2 = "My name is ";

int main(int argc, char* argv[]) {
    printf(PATTERN"Bob\n"); // Works
    // printf(PATTERN2"Bob\n"); // Breaks, since PATTERN2 is a pointer
    
    return 0;
}