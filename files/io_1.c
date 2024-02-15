#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void represent(int a){
    printf("Decimal: %d\n", a);
    printf("Hexadecimal: %08x\n", a);
    printf("Octal: %011o\n", a);
    
    printf("Binary: ");
    long long i, j;
    for (i = 0; i < sizeof(int); i++) {
        char byte = ((char*)&a)[i];
        for (j = 7; j >= 0; j--) {
            char bit = (byte >> j) & 1;
            printf("%hhd", bit);
        }
        printf(" ");
    }
    printf("\n");
}


int main(int argc, char* argv[]) {
    represent(13);
    represent(-13);    
    return 0;
}