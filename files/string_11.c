#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char str[] = "0210";
    long int x = strtol(str, NULL, 10);
    printf("The number is %d\n", x);
    
    char str2[] = "210.5";
    float y = strtof(str2, NULL);
    printf("The number is %f\n", y);
    
    return 0;
}