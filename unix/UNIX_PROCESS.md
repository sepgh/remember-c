# Unix Processes


## Exec functions

The `exec` functions will attach the current process to the executed command. This means when the command exits, the rest of our code will not execute (not a subprocess).

For windows we can include `process.h`, for linux `unistd.h`.


File: [unix_process_1.c](../files/unix/unix_process_1.c)
Video: https://www.youtube.com/watch?v=OVFEWSP7n8c
