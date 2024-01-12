# Remember C

I'm very new to C programming language. Well, here I am trying to note down some concepts as I am learning them so that I remember them better (hopefully) :thinking:.


## Intro

Since I was familiar with programming (mostly in Java) the basic syntax of C wasn't hard to follow.

The playlist below was how I refreshed my memory of C syntax (plus introdution to `&`address, `*`pointers and `struct`).

[C Programming Tutorials - Caleb Curry](https://www.youtube.com/playlist?list=PL_c9BZzLwBRKKqOc9TJz1pP0ASrxLMtp2)

Next playlist that I am going through right now is called [The C programming language made easy - Code Vault](https://www.youtube.com/watch?v=ypG9W33LOTk&list=PLfqABt5AS4FmErobw8YyTwXDUE5nPH5lH&index=1)
I was introduced to the playlist when I wanted to learn more about memory management in C and I found it to be facinating.

There are more playlists that I will check out next (or maybe sooner), but of course I will skip what I already know. Here they are:

- https://www.youtube.com/playlist?list=PLLh1tBHv1CiVpzohtrp7YCSpY9wlJxCQs
- [Stanford University - C programming](https://www.youtube.com/playlist?list=PLjn3WmBeabPOUzxcCkzk4jYMGRZMZ6ylF)


## Content

### Decimal representation of a binary number

Get a binary number as input (ex: `1001`) and print the decimal value (ex: `9`).

File: [binary_conversion.c](files/binary_conversion.c)

[Hex to decimal](https://www.youtube.com/watch?v=pg-HEGBpCQk)


## Strings

### Decleration

By using `char[]` we can later manipulate the characters of a string. But if we use `char*` the behaviour would be undetermined by C if we want to change it later (Segmentation fault). Another solution is to use `malloc` to use pointer.

Video: https://www.youtube.com/watch?v=gTXRfETK3z4

File: [string_1.c](files/string_1.c)  (misses `malloc` implementation cause I havent yet learned that completely :D)

### String Array Declerations

Video: https://www.youtube.com/watch?v=ly66E_LGubk

File: [string_2.c](files/string_2.c) 


### String copy

Functions used: `strcpy` and `strncpy`

Importance of the video: getting length of a string, having the `\0` at end of strings and what happens if we don't pay attention to that.

Additinally it helps to copy strings in safe way. Basically, using `strncpy` we can pass `length of the string + 1` (`strlen(x) + 1`) to always assure that we allocate enough memory to the string we are copying into. Alternatively, we could always set last item of char array (string) to `\0` for assurance.

Video: https://www.youtube.com/watch?v=R5Xk5N9-rno
File: [string_3.c](files/string_3.c)


### Pointer assignment vs strcpy 

If we assign value to a pointer (char pointer) - which had initial value using `malloc`- inside a function, the memory it's refering to will be deallocated after function exits, which means we can no longer get that value outside the function (in the example file, we can no longer print `str` in main function if we have used `str=example` in `process` function).


Video: https://www.youtube.com/watch?v=VQHK2EZZHb8
File: [string_4.c](files/string_3.c)


## Void pointer

Imagine we have a function that takes in "an int array" and "int of length of the array" to represent eatch array element in hex format. How can we modify this function to accept other types like `long long` or `short` instead of only `int array`.

Video: https://www.youtube.com/watch?v=k3DbBOZRvRs

File: [void_pointers.c](files/void_pointers.c)

Important note:  if you convert int array to char array (for example), the conversion is a byte conversion. An int is 4 bytes while a char is 1 byte. So if `int_arr[0]` is `64`, the converted `char_arr` will have `char_arr[0], char_arr[1], char_arr[2], char_arr[3]` to hold all of the values, and in this case only `char_arr[0]` will have a value.

Thats why in the above file if we want to present hexadeimal of an integer, we use `%08x` since each byte requires 2 hexadecimal spaces to be shown and we have 4 bytes. But after we convert the `int` or `long long` array to `char` array (through accepting it using `void*`) then to represent char array using hexadecimal we use `%02` since a char is single byte.

File: [void_pointers_2.c](files/void_pointers_2.c)


## Memory manipulation

Functions (all work on arrays):

- `memcmp`: memory comparing
- `memcp`: memory copy
- `memset`: set value in memory
- `memchr`: find byte in memory

Video: https://www.youtube.com/watch?v=ypG9W33LOTk

Files: [memory_manipulation.c](files/memory_manipulation.c)  [memory_manipulation_2.c](files/memory_manipulation_2.c)  [memory_manipulation_3.c](files/memory_manipulation_3.c)  [memory_manipulation_4.c](files/memory_manipulation_4.c) 



