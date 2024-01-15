#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char str[] = "Apples are good for your health";
    char to_find[] = "good";
    
    char* res = strstr(str, to_find);
    
    if (res) {
        printf("%p\n", res);
        printf("The word has been found at position %d\n", res - str);
    } else {
        printf("%p\n", res);
        printf("The word has NOT been found\n");
    }
    
    return 0;
}