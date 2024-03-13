#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    if (mkfifo("myfifo1", 0777) == -1) {
        if (errno != EEXIST) {
            printf("Could not create fifo file\n");
            return 1;
        }
    }
    
    printf("Opening...\n");
    int fd = open("myfifo1", O_WRONLY);
    printf("Opened\n");
    int x = 97;
    if (write(fd, &x, sizeof(x)) == -1) {
        return 2;
    }
    
    printf("Written\n");
    close(fd);
    printf("Closed\n");
    
    return 0;
}