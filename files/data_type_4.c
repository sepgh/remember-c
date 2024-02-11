#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct CustomFloat {
    bool isExtended;
    union {
        float value;
        double valueExtended;
    };
} CustomFloat;

int main(int argc, char* argv[]) {
    CustomFloat cf, cf2;
    cf.isExtended = false;
    cf.value = 12.5f;
    
    cf2.isExtended = true;
    cf2.valueExtended = 0.25;
    return 0;
}