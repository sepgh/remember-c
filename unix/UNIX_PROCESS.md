# Unix Processes


## Exec functions

The `exec` functions will attach the current process to the executed command. This means when the command exits, the rest of our code will not execute (not a subprocess).

For windows we can include `process.h`, for linux `unistd.h`.


File: [unix_process_1.c](../files/unix/unix_process_1.c)
Video: https://www.youtube.com/watch?v=OVFEWSP7n8c


## Fork

`fork` is a function call which creates a subprocess that continues execution of the program, on whenever you call this function, the rest of the code will be executing in one more process. The output of the `fork()` call is an `int` which is the process id. If the value is `0` it means its the the child process, otherwise it will be pid of main process.

```c
int pid = fork()

// Both executing
if (pid == 0){
    // Child executing
} else {
    // Parent executing
}
```

Calling `fork` for N times will result in 2 to the power of N processes.

File: [unix_process_2.c](../files/unix/unix_process_2.c)
Video: https://www.youtube.com/watch?v=cex9XrZCU14

> fork() returns the process id of the CHILD process in the parent process and 0 in the child process

### Memory

Each process have their own space in the memory. When you call fork anything that was stored in the memory before the call to fork will be copied to the new subprocess. Therefore, anything that is stored in the memory after the fork call is placed in different places of memory for each process.


### Fork - Wait  (sys/wait.h)

To wait for a child process to exit we can use `wait()` function. The wait function waits for ONLY ONE of the children to finish.

File: [unix_process_3.c](../files/unix/unix_process_3.c)
Video: https://www.youtube.com/watch?v=tcYo6hipaSA
 

Side note: `fflush(stdout)` will flush the output buffer into standard output, which is useful especially when there are forks involved.



## Process Id

- `getpid()` returns current process id.
- `getppid()` returns parent process id. Every process (even main) has a parent process in the system.

> In any program that uses fork we have to make sure to stop or wait for the termination of child processes before exiting parent process or we may create memory leaks.

> We can check output of  `wait(NULL)` and if its `-1` then there are no processes to wait for.

Video: https://www.youtube.com/watch?v=PZrQ4eGm-hM


## Waiting for all processes to finish

We need to include `<errno.h>`.

Syntax would become: `while(wait(NULL) != -1 || errno != ECHILD);`


File: [unix_process_4.c](../files/unix/unix_process_4.c)
Video: https://www.youtube.com/watch?v=94URLRsjqMQ

> A common good practice is to start new child process only from the most parent process


## Pipe

`pipe` function requires an array of two integers to store "File descriptiors" into. The descriptor at index 1 is to write into and the one at index 0 is to read from. After writing or reading to/from each of the files we have to close them. The function can be used for communicating between processes. The function returns 0 if its successful or -1 if it fails.


File: [unix_process_5.c](../files/unix/unix_process_5.c)
Video: https://www.youtube.com/watch?v=Mqb2dVRe0uo


### Fork and Pipe practical example

Basically using fork we can distribute the processing into different parallel processes, and using pipe we can gather processed information from subprocesses.

In the code and video example below, we `sum` an array using two subprocesses.

File: [unix_process_6.c](../files/unix/unix_process_6.c)
Video: https://www.youtube.com/watch?v=6u_iPGVkfZ4


## FIFO (named pipe)

FIFO is a especial file which is used like a pipe for process communications. Unlike pipe, it can be used for communication between processes that are not in same hirarchy (not a parent child process). To use it we need `<fcntl.h>` and `<errno.h>` included, as well as `unistd` like before.

To use FIFO, we should first create one using `mkfifo(PATH, PERMISSION)` command like `mkfifo("/temp/something", 0777)`. If the output of this command is -1 then something went wrong. We can use `errno` and compare it with `EEXIST` to see if the fifo file is created or not.

```c
if (mkfifo("myfifo1", 0777) == -1) {
    if (errno != EEXIST) {
        printf("Could not create fifo file\n");
        return 1;
    }
}
```

Afterwards, we should treat the file like a normal file! In the process that we want to write into the file we should `open` it with `O_WRONLY` flag. This function call will become "blocking" in that case. The current execution line will wait for another process to open the file to read from it. Afterwards, whatever is written into the file will come out from the reading process. The reading process can simply even be linux `cat` command.


File: [unix_process_7.c](../files/unix/unix_process_7.c)
Video: https://www.youtube.com/watch?v=2hba3etpoJg


## Executing commands

Idea is to create a fork and then use `exec` function in a subprocess so main process wont be attacked to the exec.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    
    if (pid == 0) {
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
        printf("THIS SHOULD NOT PRINT ON THE TERMINAL\n");
    } else {
        wait(NULL);
        printf("Success\n");
        printf("Some post processing goes here\n");
    }

    return 0;
}
```

**IMPORTANT**:  exec functions do not act like shell/bash. You cant use grep or pipe (`|`) or such things in the arguments. It's directly passing arguments to the executable.


## Get Error code from exec

If exec functions themselves fail the function will return -1. But what if the command we are executing returns error?

In the code above, if instead of `NULL` we pass address of an integer to `wait` function we can get the exit status code. So in parent process:

```c
int wstatus;
wait(&wstatus);
if (WIFEXTED(wstatus)){  // check if program was not just killed
    int statusCode = WEXITSTATUS(wstatus);
    if (statusCode == 0){
        //success
    }else{
        //err
    }
}
```

Video: https://www.youtube.com/watch?v=DiNmwwQWl0g


## Redirecting standard output

First, lets note few things about File Handles / Descriptors:

> A file descriptor is an int (for example returned by `open()`) which is a key that OS will keep for **each process** to remember which file to modify/read from when that descriptor is used.

> Additionally, when any new process spawns, the STDIN and STDOUT (and STDERR) descriptors are opened for the process, with ids 0, 1, 2 (USUALLY). So new handles get 4,5, ...

So the whole trick here is to replace `STDOUT` descriptor to point to another descriptor.

The function `dup(int handle)` duplicates a handle to a file (same file as the input). Function `dup2(source, destination)` duplicates the source handle into destination. So `dup2(file, STDOUT_FILENO)` would replace STDOUT with the file we are passing the handle of as source.


File: [unix_process_8.c](../files/unix/unix_process_8.c)
Video: https://www.youtube.com/watch?v=5fnVr-zH-SE


## Signals

We can use `kill(PROCESS_ID, SIGNAL)` to send signal to another process. Example: `kill(pid, SIGKILL);`.

- https://www-uxsup.csx.cam.ac.uk/courses/moved.Building/signals.pdf
- https://man7.org/linux/man-pages/man7/signal.7.html

Video: https://www.youtube.com/watch?v=5We_HtLlAbs

