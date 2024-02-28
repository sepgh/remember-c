#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long sum(int a, int b) {
    return a + b;
}

long long mul(int a, int b) {
    return a * b;
}

int main(int argc, char* argv[]) {
    long long (*fun)(int, int);
    
    fun = &sum;
    printf("%lld\n", fun(5, 7));
    fun = &mul;
    printf("%lld\n", fun(5, 7));
    return 0;
}