#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char* arr[] = {
        "ping",
        "google.com",
        NULL
    };
    
    char* env[] = {
        "TEST=environment variables",
        NULL
    };
    
    // Without env and PATH variable
    _execv("C:\\Windows\\System32\\ping.exe", "C:\\Windows\\System32\\ping.exe", "google.com", NULL);
    _execl("C:\\Windows\\System32\\ping", arr);
    
    // Without env but with PATH variable
    _execvp("ping", "ping", "google.com", NULL);
    _execlp("ping", arr);
    
    // With env and PATH variable
    _execvpe("ping", "ping", "google.com", NULL, env);
    _execlpe("ping", arr, env);
    

    return 0;
}