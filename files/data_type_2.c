#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int x) {
    static int sum = 0;
    sum += x;
    return sum;
}

int main(int argc, char* argv[]) {
    printf("%d\n", add(5));
    printf("%d\n", add(5));
    printf("%d\n", add(5));
    printf("%d\n", add(5));
    
    // Doesn't work, sum is not defined in this scope
    //printf("%d\n", sum);
    return 0;
}