#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int fd[2];
    if (pipe(fd) == -1) {
        printf("An error ocurred with opening the pipe\n");
        return 1;
    }
    
    int id = fork();
    if (id == -1) {
        printf("An error ocurred with fork\n");
        return 2;
    }
    
    if (id == 0) {
        // Child process
        close(fd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1) {
            printf("An error ocurred with writing to the pipe\n");
            return 3;
        }
        close(fd[1]);
    } else {
        // Parent process
        close(fd[1]);
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1) {
            printf("An error ocurred with reading from the pipe\n");
            return 4;
        }
        printf("Got from child process %d\n", y);
        y = y * 3;
        printf("Result is %d\n", y);
        close(fd[0]);
    }
    
    return 0;
}