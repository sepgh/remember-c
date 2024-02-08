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
File: [string_4.c](files/string_4.c)


### Comparing strings

Intro to `strcpy` and `strncpy`. Additionally you can use `memcmp`.


Video: https://www.youtube.com/watch?v=Y4OABXkRSEA
File: [string_5.c](files/string_5.c)


### Finding a character in a string (checking if character exists)

Intro to `strchr` and `strrchr`. Additionally explains how to get the position of found character.

**Fun point!** Both of these functions return pointer of the found character, and since a string is a "contiguous" array of characters, subtracting these pointer addresses will return you the position of which the character was found in a string.


Video: https://www.youtube.com/watch?v=SLUEfPKR91U
File: [string_6.c](files/string_6.c)


### Finding words in a sentence

Intro do `strstr`.

Video: https://www.youtube.com/watch?v=8A3Zycio0W4
File: [string_10.c](files/string_10.c)



### Return a string from a function

The best way to do so is to allocate the memory of the string we "expect to be returned" before calling the function and pass the memory of that string to the function so it fills it.

Video: https://www.youtube.com/watch?v=A8IkGIqZoLQ
File: [string_7.c](files/string_7.c)


### Splitting strings

Intro to `strtok` (String token). Importance:
This function returns a char* to next occurrence of each piece. Also modifies the input (str) and adds "String terminator character" at each piece.

Video: https://www.youtube.com/watch?v=34DnZ2ewyZo
File: [string_8.c](files/string_8.c)


### String parsing

Intro to `sscanf` (different from `scanf`). Scans a string.

Video: https://www.youtube.com/watch?v=-7cSmcdMryo
File: [string_9.c](files/string_9.c)

Additional note: `scanf` is a family of functions in C that not only work from standard input from keyboard, it works with strings and files.

Additional note: `%s` reads anything until `\n`, `space` or a tab. So we can't use `%s` (format specifier) for some cases in `sscanf`. Instead we can do something like `%[a-zA-Z ]` for example. If we want to read anything we can use `%[^]`.

Same thing works with `scanf`, so `sscanf` is for scanning and parsing strings, and you could use `fscanf` to do the same with files and pass a "file handle".


### String to number

Intro to `strtol` and `strtof`. Read like `str  to  L` (long) or `str  to  F` (float). They return a number, but takes more parameters. Second parameter takes a pointer to set it to where it stopped reading the number. Third parameter is the base we want to read the number in.

Also, `atoi` is introduced, which is not the right way to do because: A) has undefined behavior if you try to convert a string larger than expected. B) Doesn't tell you when it stopped converting a number. C) Can't convert numbers from other bases (like base 16).

Video: https://www.youtube.com/watch?v=UQ5INK_pXCI
File: [string_11.c](files/string_11.c)


### Parsing a string of numbers

Intro to `strtol`, which takes out numbers (long int) from a string. It takes the string, the pointer of the string we are in, and the base we read the number in. If you use `0` as base it detects base-16 itself.

Video: https://www.youtube.com/watch?v=L8hVbPIVE0U
Source:

```c
//char str[] = "200, 22, 111 ";
char str[] = "200, 0xf ";
char* cursor = str;
long int sum = 0;
while (cursor != str + strlen(str)) {
    // long int x = strtol(cursor, &cursor, 10);
    long int x = strtol(cursor, &cursor, 0);
    while (*cursor == ' ' || *cursor == ',') {
        cursor++;
    }
    sum += x;
}
printf("Sum is %ld\n", sum);
```

## Arrays

### Iterating over an array using pointers

If we declare a pointer to the first element of an array (Example:  `int* p = &arr[0]`), we can access the value using `*p`. But also, if we increment the pointer by the `sizeof` the array type (in this example, `int` which is 4 bytes) then we can get the next item in the array.

Video: https://code-vault.net/course/ar67avx6hk:1610029043923/lesson/qjp3te6iyf:1603733521836


### Iterating main parts of a matrix

Video: https://code-vault.net/course/ar67avx6hk:1610029043923/lesson/rrpv5yuflb:1603733521478


### Returning an array from a function

An array which is declared within a function can not be returnes since the memory is in the stack and is removed when the function exits. The right way to do it is either accept the array address as input, return void, and manipulate the array in the function, or use `malloc` and return the address of the array which then will require a call to `free` whenever the function is called.  This is the same practice from __Strings: Pointer assignment vs strcpy__ section.

Video: https://code-vault.net/course/ar67avx6hk:1610029043923/lesson/iyvrv54u8e:1603733520962


### Difference between arrays and pointers

Video: https://www.youtube.com/watch?v=iSZLE9qPN14


### Dynamically allocated arrays

Intro to `calloc`. From man page:

> The calloc() function allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.  The memory is set to zero.  If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer value that can later be successfully passed to free().  If the multiplication of nmemb and size would result in integer overflow,  then  calloc()  returns an error.  By contrast, an integer overflow would not be detected in the following call to malloc(), with the result that an incorrectly sized block of memory would be allocated:
>
>           malloc(nmemb * size);

If calloc returns NULL it means it failed to allocate the memory (maybe no memory was left for example). We can gracefully handle the error. Same principle applies to realloc (read below).

Intro to `size_t`:

> size_t is a special unsigned integer type defined in the standard library of C and C++ languages. It is the type of the result returned by the sizeof and alignof operators. The size_t is chosen so that it can store the maximum size of a theoretically possible array or an object.

Intro to `realloc`, which gets a pointer and allocates a chunk of memory to it again. It may return a new pointer, since it may not just simply be able to expand the memory and have to move it.


video: https://www.youtube.com/watch?v=6Ir4l0VuI7Y


### The address of an array

Most important lesson: Arrays decay to a pointer whenever they are passed to a function.

Videos: https://www.youtube.com/watch?v=ToPkRyNOBZ8 | https://www.youtube.com/watch?v=pBPrWFhVNL4


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



