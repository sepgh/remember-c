#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct point
{
    int x,y
} Point;



int main(int argc, char* argv[]) {
    Point p1 = {
        .x = 12, .y=20
    };

    FILE* in;
    FILE* out;
    
    char buffer_in[256], buffer_out[256];
    out = fopen("point.dat", "w");
    if (out == NULL) {
        return 1;
    }
    
    snprintf(buffer_out, 256, "%d %d\n", p1.x, p1.y);
    size_t bytesWrote = fwrite(buffer_out, sizeof(char), strlen(buffer_out), out);
    fclose(out);
    
    if (bytesWrote != strlen(buffer_out)) {
        return 1;
    }
    return 0;
}