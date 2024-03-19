# Unix Threads

Threads are part of `pthread.h` and also when using them we should compile the code (gcc) with `-pthread` argument included.


## Thread creation

- a `pthread_t` struct is required which holds reference to the thread
- a routine / function is required to run inside the thread. The function can return something as well.
- `pthread_create(POINTER_TO_PTHREADT_STRUCT, ATTRIBUTES, POINTER_TO_FUNCTION, ARGUMENT_OF_FUNC)` is used to create and run the tread
- `pthread_join(POINTER_TO_PTHREADT_STRUCT, POINTER_TO_GET_RESULTS_OF_THREAD)` to join the thread in the process and wait for it to end.


