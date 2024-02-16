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
    
    FILE* file;

    file = fopen("point.dat", "w+");
    if (file == NULL) {
        return 1;
    }
    
    size_t bytes_wrote = fprintf(file, "%d, %d\n", p1.x, p1.y);
    if (bytes_wrote <= 0) {
        return 2;
    }
    
    // -- READ --
    int elements_read = fscanf(file, "%d, %d\n", &p2.x, &p2.y);
    fclose(file);
    if (elements_read < 2) {
        return 3;
    }
    
    printf("Read from file the point: %d %d\n", p2.x, p2.y);
    
    return 0;
}