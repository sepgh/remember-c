#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int arr[] = { 1, 2, 3, 4, 1, 2, 7, 7 };
    int arrSize = sizeof(arr) / sizeof(int);
    int start, end;
    int fd[2];
    if (pipe(fd) == -1) {
        return 1;
    }
    
    int id = fork();
    if (id == -1) {
        return 2;
    }
    
    if (id == 0) {
        start = 0;
        end = arrSize / 2;
    } else {
        start = arrSize / 2;
        end = arrSize;
    }
    
    int sum = 0;
    int i;
    for (i = start; i < end; i++) {
        sum += arr[i];
    }
    
    printf("Calculated partial sum: %d\n", sum);
    
    if (id == 0) {
        close(fd[0]);
        if (write(fd[1], &sum, sizeof(int)) == -1) {
            return 3;
        }
        close(fd[1]);
    } else {
        int sumFromChild;
        close(fd[1]);
        if (read(fd[0], &sumFromChild, sizeof(int)) == -1) {
            return 4;
        }
        close(fd[0]);
        
        int totalSum = sum + sumFromChild;
        printf("Total sum is %d\n", totalSum);
        wait(NULL);
    }
    
    return 0;
}