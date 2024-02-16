#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point {
    int x, y;
} Point;

int main(int argc, char* argv[]) {
    Point p1 = {
        .x = 13,
        .y = -1
    };
    Point p2;
    
    FILE* in;
    FILE* out;
    
    out = fopen("point.bin", "wb");
    if (out == NULL) {
        return 1;
    }
    
    size_t elements_written = fwrite(&p1, sizeof(Point), 1, out);
    fclose(out);
    if (elements_written == 0) {
        return 2;
    }
    
    in = fopen("point.bin", "rb");
    if (in == NULL) {
        return 3;
    }
    
    size_t elements_read = fread(&p2, sizeof(Point), 1, in);
    fclose(in);
    if (elements_read == 0) {
        return 4;
    }
    
    printf("Point read from binary file: %d, %d\n", p2.x, p2.y);
    
    return 0;
}