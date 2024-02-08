#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long UINT64;
typedef struct Point {
    double x, y;
} Point;

int main(int argc, char* argv[]) {
    Point p;
    p.x = 0.24;
    p.y = 0.78;
    printf("%lf %lf\n", p.x, p.y);
    UINT64 l = 14;
    printf("%llu\n", l);
    return 0;
}