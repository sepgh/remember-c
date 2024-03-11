# Unix Processes


## Exec functions

The `exec` functions will attach the current process to the executed command. This means when the command exits, the rest of our code will not execute (not a subprocess).

For windows we can include `process.h`, for linux `unistd.h`.


File: [unix_process_1.c](../files/unix/unix_process_1.c)
Video: https://www.youtube.com/watch?v=OVFEWSP7n8c


## Fork

`fork` is a function call which creates a subprocess that continues execution of the program, on whenever you call this function, the rest of the code will be executing in one more process. The output of the `fork()` call is an `int` which is the process id. If the value is `0` it means its not the the child process.

```c
int pid = fork()

// Both executing
if (pid == 0){
    // Parent executing
} else {
    // Child executing
}
```

Calling `fork` for N times will result in 2 to the power of N processes.

File: [unix_process_2.c](../files/unix/unix_process_2.c)
Video: https://www.youtube.com/watch?v=cex9XrZCU14


