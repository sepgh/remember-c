# Unix Threads

Threads are part of `pthread.h` and also when using them we should compile the code (gcc) with `-pthread` argument included.


## Thread creation

- a `pthread_t` struct is required which holds reference to the thread
- a routine / function is required to run inside the thread. The function can return something as well but shall be a pointer.
- `pthread_create(POINTER_TO_PTHREADT_STRUCT, ATTRIBUTES, POINTER_TO_FUNCTION, ARGUMENT_OF_FUNC)` is used to create and run the tread
- `pthread_join(POINTER_TO_PTHREADT_STRUCT, POINTER_TO_GET_RESULTS_OF_THREAD)` to join the thread in the process and wait for it to end.


## Mutex - Locking - Preventing race conditions

- We hold the mutex struct as global variable: `pthread_mutex_t mutex;`
- In the process before starting threads we initialize the mutex: `pthread_mutex_init(&mutex, NULL);`
- In the process after threads finish we destroy the mutex: `pthread_mutex_destroy(&mutex, NULL);`
- To use the mutex in the threads: `pthread_mutex_lock(&mutex);` to lock, `pthread_mutex_unlock(&mutex);` to unlock.


Code: [unix_thread_2.c](../files/unix/unix_thread_2.c)
Video: https://www.youtube.com/watch?v=oq29KUy29iQ

Additional: [How does mutex work internally](https://mortoray.com/how-does-a-mutex-work-what-does-it-cost/)

