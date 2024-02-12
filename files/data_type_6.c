#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    STACK_INT,
    STACK_CHAR,
    STACK_UINT64
} DataType;

typedef struct Stack {
    DataType type;
    size_t size;
    void* data;
    void* top;
} Stack;


Stack stackCreate(size_t size, DataType type) {
    size_t effectiveSize = 0;
    if (type == STACK_CHAR) {
        effectiveSize = size * sizeof(char);
    } else if (type == STACK_INT) {
        effectiveSize = size * sizeof(int);
    } else if (type == STACK_UINT64) {
        effectiveSize = size * sizeof(unsigned long long);
    }
    
    Stack s = {
        .type = type,
        .size = size,
        .data = malloc(effectiveSize),
        .top = NULL
    };
    
    return s;
}

void stackDelete(Stack* s) {
    free(s->data);
    s->data = NULL;
}

void stackPush(Stack* s, void* elem) {
    // Homework ;)
}

int main(int argc, char* argv[]) {
    Stack s = stackCreate(10, STACK_INT);
    ((int*)s.data)[0] = 64;
    s.top = ((int*)s.data) + 0;
    
    ((int*)s.data)[1] = 128;
    s.top = ((int*)s.data) + 1;


    return 0;
}