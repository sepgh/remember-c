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


### Fork - Wait

To wait for a child process to exit we can use `wait()` function.

File: [unix_process_3.c](../files/unix/unix_process_3.c)
Video: https://www.youtube.com/watch?v=tcYo6hipaSA


Side note: `fflush(stdout)` will flush the output buffer into standard output, which is useful especially when there are forks involved.

