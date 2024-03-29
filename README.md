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

---

## Custom Content

### Decimal representation of a binary number

Get a binary number as input (ex: `1001`) and print the decimal value (ex: `9`).

File: [binary_conversion.c](files/binary_conversion.c)

[Hex to decimal](https://www.youtube.com/watch?v=pg-HEGBpCQk)


### Header files

__note__: `#inclue <something.h>` works for external files and `#include "something.h"` works for local project files.

In a single compilation unit, all c files are compiled, so you can use a function from another c file in the file with `main` method. But then if you use `#include 'util.c'` it will try act as copying the content of that file into your current file, and as a result the function will be declared twice which results as a problem.

Header files only contain _signature_ of declaraions such as functions. Therefore when they are included in another file, they only define signature of functions and not implement them. This is the difference between declare and define. Declare means the signature is there, define means the implementation is there. Example:

```c
//Declare:
void func(int a);

//Define
void func(int a){
    return a + 1;
}
```

#### Pragma once

You may see/use `#pragma once` or below code in a header file:

```c
#ifndef SOMEFILE_H
#define SOMEFILE_H

// code (declarations) here

#endif
```

This prevents the file to be redeclared, or better say this file will only be included once.


Video: https://www.youtube.com/watch?v=u1e0gLoz1SU


#### Sharing functions between C files

Video: https://www.youtube.com/watch?v=8tRQ96W4g84


### Macros

Readings:  https://stackoverflow.com/questions/1358232   https://stackoverflow.com/questions/66618214/

Video: https://www.youtube.com/watch?v=JqN4uVgCTWE


## Strings

### Decleration

By using `char[]` we can later manipulate the characters of a string. But if we use `char*` the behaviour would be undetermined by C if we want to change it later (Segmentation fault). Another solution is to use `malloc` to use pointer.

Video: https://www.youtube.com/watch?v=gTXRfETK3z4

File: [string_1.c](files/string_1.c)  (misses `malloc` implementation cause I havent yet learned that completely :D)

### String Array Declerations

Video: https://www.youtube.com/watch?v=ly66E_LGubk

File: [string_2.c](files/string_2.c) 


### String storage

Strings are usually neither stored on heap or stack. They are stored in [Data Segments](https://en.wikipedia.org/wiki/Data_segment). Later we will see that creating a variable within a function and returning it, or pointing a pointer to a new variable within functions may not work on some data types, such as arrays (check [Arrays > Returning an array from a function] section). But that doesn't apply to strings even though you may think its just a char array.

[More info](https://stackoverflow.com/questions/4970823/)


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

Video for `size_t`: https://www.youtube.com/watch?v=gWOeL1oymrc

Intro to `realloc`, which gets a pointer and allocates a chunk of memory to it again. It may return a new pointer, since it may not just simply be able to expand the memory and have to move it.


Video: https://www.youtube.com/watch?v=6Ir4l0VuI7Y


**Bonus**: Dynamically allocated multi-dimensional arrays!

Video: https://www.youtube.com/watch?v=-y8FUvRq_88
File: [array_1.c](files/array_1.c)


### The address of an array

Most important lesson: Arrays decay to a pointer whenever they are passed to a function.

Videos: https://www.youtube.com/watch?v=ToPkRyNOBZ8 | https://www.youtube.com/watch?v=pBPrWFhVNL4


### Passing arrays to a function (tricky with multidimensional arrays)

Video: https://www.youtube.com/watch?v=Cfm4D_Mxpiw
File: [array_2.c](files/array_2.c)


## Void pointer

Imagine we have a function that takes in "an int array" and "int of length of the array" to represent each array element in hex format. How can we modify this function to accept other types like `long long` or `short` instead of only `int array`.

Video: https://www.youtube.com/watch?v=k3DbBOZRvRs

File: [void_pointers.c](files/void_pointers.c)

Important note:  if you convert int array to char array (for example), the conversion is a byte conversion. An int is 4 bytes while a char is 1 byte. So if `int_arr[0]` is `64`, the converted `char_arr` will have `char_arr[0], char_arr[1], char_arr[2], char_arr[3]` to hold all of the values, and in this case only `char_arr[0]` will have a value.

Thats why in the above file if we want to present hexadeimal of an integer, we use `%08x` since each byte requires 2 hexadecimal spaces to be shown and we have 4 bytes. But after we convert the `int` or `long long` array to `char` array (through accepting it using `void*`) then to represent char array using hexadecimal we use `%02` since a char is single byte.

File: [void_pointers_2.c](files/void_pointers_2.c)

Bonus videos:

- https://www.youtube.com/watch?v=t7CUti_7d7c

## Functions

### Func Pointers

Video: https://www.youtube.com/watch?v=ewBBRaF0oEA
File: [function_1.c](files/function_1.c)


## Data types

### typedef

Using `typedef` you can define a name for a data type. It can be a data type you create (like struct) or even built in types.

Video: https://www.youtube.com/watch?v=9guJVmDyFmE
File: [data_type_1.c](files/data_type_1.c)


### Defining a data type (struct)

Example:

```c
typedef struct Point {
    double x;
    double y;
} Point;

int main(int argc, char* argv[]) {
    Point p = {
        .x = 0.25,
        .y = 0.78
    };
    
    printf("%lf %lf\n", p.x, p.y);
    
    return 0;
}
```

**Important note:** even though struct is usually stored in a contiguous memory, the value of `sizeof(structInstance)` may not be equal to the sum of the struct attributes.
This has to do with memory padding.

### Return and pass a struct to a function

1. Passing struct to a function is pass-by-value (copy), which is not optimized.
2. As solution for 1, arguments can accept pointers to the structs.  `void x(Point* p)`
3. To prevent modification, arguments can also be set as `const`.  `void x(const Point* p)`
4. Accessing struct attributes when passed as a pointer needs `->` instead of `.`. So: `p->x` over `p.x`.

Video: https://www.youtube.com/watch?v=XreVazVRQEI


### Static

The `static` keyword makes variables be treated specially: To be initialized when program starts, and during execution don't reinitialize it, therefore it's value and state doesn't refresh when stack of a function is cleaned. **This is not a global variable though. They are accessible only in their own scope.**

Video: https://www.youtube.com/watch?v=OngGUoENgWo
File: [data_type_2.c](files/data_type_2.c)


### Union

Inside a Union all the members share the exact same memory. It's a simple way to interprete exact same memory in different ways.

Video: https://www.youtube.com/watch?v=BFDUeEVxUok
File: [data_type_3.c](files/data_type_3.c)


#### Bonus (Anonymous Unions)

Video: https://www.youtube.com/watch?v=ICbLwg0Pgz0
File: [data_type_4.c](files/data_type_4.c)


### Integer type conversion


When we are __extending__ the variables we take the 'sign bit' and copy it into everywhere we have to pad the larger variable. 
And when we are trying to assign a smaller variable a larger amount in size, we actually trim the first least significant bytes from the larger value.

Video: https://www.youtube.com/watch?v=am183PVCn7U


### Enum

In C, the enum can only store signed int values. The int value of each enum element will be "last value + 1" if not defined, and if no elements have any value first one begins with 0.

Video: https://www.youtube.com/watch?v=lWzZ2l5n81c


### Integer overflow and underflow

Video: https://www.youtube.com/watch?v=JNu_9U4qq8E
File: [data_type_5.c](files/data_type_5.c)


### Infinite loop through integer overflow

If for optimizing loop index we choose a type which may overflow or underflow during the loop then we will enter an infinite loop.

Video: https://www.youtube.com/watch?v=uZf_5JQXoU8


### Generic data type

(Checkout 'Void pointer' section first)

There is actually no "Generic type" like in OOP languages. It's all about using `malloc` within a struct that keeps the type as an enum.


Video: https://www.youtube.com/watch?v=RG7D2_pay0U
File: [data_type_6.c](files/data_type_6.c)


### Difference between macros and constants

Macros are processed before compilation. Their value is literally replaced in the source code as if its like a text editor is replacing them.

Video: https://www.youtube.com/watch?v=TfJHlez7bek
File: [data_type_7.c](files/data_type_7.c)


## File and Terminal IO

### Reading input from terminal

Can use `scanf`, but also `fgets` which accepts 3 parameters: 

1. the string we want to write into
2. how many characters we accept
3. where do we read from, which could be a file or `stdin` to read from terminal input

Video: https://www.youtube.com/watch?v=Lksi1HEMZgY


### Printing a struct memory to console

Example code:

```c
unsigned char data;
    for (i = 0; i < sizeof(t); i++) {
        if (i % 4 == 0) {
            printf("\n");
        }
        data = *(((unsigned char*) &t) + i);
        printf("%02x ", data);
    }
```

Video: https://www.youtube.com/watch?v=a3ropbfIpw4


### Printf variants

Examples:

- `sprintf(buff, format string, args)`, example `sprintf(buf, "Example\n");`: writes the formatted value into the buffer input (`char buffer[200]`)
- `snprintf(buff, max, format string, args)`: which accepts the maximum size to write into buffer, in case format string is longer than buffer
- `fprintf(stream, format string, args)`: writes to a stream, like a file or `stdout` or `stderr`
- `fprintf_s(stream, format string, args)`: safer version, checks for NULL in args to prevent crash
- `fwprintf_s(stream, format string, args)`: uses wide char for fstring
- `vfprintf_s(stream, format string, list_args)`: accepts list of args (`va_list` type)

Actually these are prefixes before `printf` func:

- `s` buffer
- `n` buffer size
- `f` stream (file)
- `_s` safer version
- `w` wide char
- `v` var args list (va_list)

Video: https://www.youtube.com/watch?v=VA22ESilQO0


### Binary representation of an Integer  (print in binary)

Video: https://youtu.be/Kj3iboADvUc?si=wuCvCqibsh07-uA-
File: [io_1.c](files/io_1.c)


### File IO

#### Write (basics)

In short, we use `FILE* out` to create a file pointer, and then using `fopen` or `fopen_s` we assign a handler to it. Then using `fwrite` function we can write a string buffer into that handler. To fill the buffer we can choose from _Printf variants_, like `sprintf_s`. Using `fclose` we can close the file.

File: [io_2.c](files/io_2.c)
Video: https://www.youtube.com/watch?v=da9D4Bcsrgc

The example file writes binary data into a file. Although, its only a string.

#### Write in binary:

The handler needs to be called with `wb` flag, of course. Example: `fopen("point.bin", "wb")`

File: [io_4.c](files/io_4.c)
Video: https://www.youtube.com/watch?v=P-fWNCF7Wx8

#### Read (basics)

Pretty much like write in terms of opening and closing. We use `fgets` to read file content into a buffer. We can then use `sscanf` to format the buffer.

File: [io_3.c](files/io_3.c)
Video: https://www.youtube.com/watch?v=k3gSBljW-OE


#### Read in binary

Like normal reading but with `rb` flag. We can use `fread_s` to read binary data from the file. In the example, we pass the address of `p2` to `fread_s` which is a Point struct so the binary data is written there!

File: [io_5.c](files/io_5.c)
Video: https://www.youtube.com/watch?v=dDjfaA9Q3n8


#### Read/Write improvements

Using `fprintf` and `fscanf` to reduce the need of extra buffers. Also using `w+` flag to open the file.

File: [io_6.c](files/io_6.c)
Video: https://www.youtube.com/watch?v=COypelJNUYY

### fseek

Using fseek we can move the cursor where we start reading/writing into a file.


### getc, getch, getche and getchar

These function reads a single character from console input.

- `getch` doesnt print the character to the console. Returns an int so it can store `EOF`. Not a C standard function, and only compatibel with Windows. Also, no enter needed to send the character into console.
- `getche` is same as `getch` but prints the character to console.
- `getc` expects enter to be pressed. Its a macro on some platforms.
- `getchar` equal to getc but works with `stdin` by default.
- `fgetc` is like `getc` but its a function and not a macro.


## Pointers and Memory management


### Memory paddings

Padding is something that is used to add a couple of bytes to the memory allocate so that the CPU can get it in a much faster way and in some cases don't give out errors.

The compiler tries to align every single address of every single element (element of a struct in this example) at 8 bytes. Because we dont want an element (a pointer for instance) to start in a 64 bit of a memory and end in another one, because while it may be more memory efficient, the CPU has to do more work by taking one byte into CPU and then another one and make them up together in order to find the value of that pointer. But when its aligned in the CPU architecture then it'll be easier.

This behavior can change by using `#pragma pack(1)` _before the line you want the alignment to start changing_. It basically says align everything at 1 byte, which means don't align anything. But you can also use this to align things for other CPU architectures. So for example `#pragma pack(1)` can act like 32bit architecture alignment.


Video: https://www.youtube.com/watch?v=8wHoI-6R0CQ


#### Additional on memory paddings:

Processor doesn't read 1 byte at time from memory. It reads 1 "word" at a time. A word for 32 bit processor is 4 bytes for example.

Additional video: https://www.youtube.com/watch?v=aROgtACPjjg


### add or subtract two pointers

Giving

```c
long long c[] = {1,2,3};
```

  a pointer like `long long* p = c + 1` gets the address of c and **adds 1 times of `sizeof(type of c)`. So `c + 1` doesn't add just one byte to the address, but 8 bytes in this case.

General rule: pointer arithmetics are done at the size of the pointer type.

Note: in stack, the pointer value of a variable that is defined last is lower than the one that is defined first. While in heap this may not be true.


### Memory manipulation

Functions (all work on arrays):

- `memcmp`: memory comparing
- `memcp`: memory copy
- `memset`: set value in memory
- `memchr`: find byte in memory

Video: https://www.youtube.com/watch?v=ypG9W33LOTk

Files: [memory_manipulation.c](files/memory_manipulation.c)  [memory_manipulation_2.c](files/memory_manipulation_2.c)  [memory_manipulation_3.c](files/memory_manipulation_3.c)  [memory_manipulation_4.c](files/memory_manipulation_4.c) 


### Memory allocaction

`malloc` allocates memory for given size and returns `void*` to the initial byte of the allocated memory. **important:** `malloc` DOES NOT set the memory to 0; In fact the allocated memory may have some values in it since `free()` only tells OS to let go of a memory for the process and doesn't tell it to set it to 0. `malloc` needs a check if returned pointer is NULL.

Using `memset` we can set everything to something (example `0`), for example the result of the `malloc`.

Alternatively we can allocate an array using `calloc` and it'll create an array with initial values of `0`.

`realloc` can be used to shrink/expand allocated memory. Lets say we `malloc`'d 256 bytes and organized some values to take only `64` byte. Instead of allocating a new 64 byte memory and move/copy the organized memory there we can shring the already allocated 256 bytes of memory. **important**: `realloc` may have to move the data to somewhere else, therefore it returns a new pointer. We can do something like `p = realloc(p, 64 * sizeof(int))` so our previous pointer will eventually point to the new location in case `realloc` moved the data. It still needs a check if returned pointer is NULL.


### Pointer declarion quirks

To declare multiple pointers in same line, doing this is wrong: `int* a, b` and makes `b` just an `int` and not a pointer. Doing this is right: `int *a, *b`.

`char* str[20]` creates 20 character pointers.


### Function pointers

To declare a function pointer we use something like: `{RETURN TYPE} (*{POINTER NAME})({ARG 1 TYPE}, {ARG 2 TYPE})`, for example: `long long (*func)(int, int)` would be a pointer named `func` to a function that returns `long long` and has 2 arguments both of type `int`.

To make the pointer point to a function we can do `{POINTER NAME} = &{FUNCTION NAME}` like `func = &sum` where `func` is the pointer name and `sum` is name of the function.

The notation (`{RETURN TYPE} (*{POINTER NAME})({ARG 1 TYPE}, {ARG 2 TYPE})`) can be used as a function argument itself, for passing a function to another function.


file: [memory_management.c](files/memory_management.c)
video: https://www.youtube.com/watch?v=cwvdT-4HT9o


### Pointer address of an array

Considering we have `char str[20] = "Example string";`, to get the pointer to the beginning of the variable, our best choice can be `str` or `&str[0]`. If we -_wrongly_- use `&str`, our pointer arithmetics will be messed with, since `str + 1` or `&str[0] + 1` will return address of the second element, but `&str + 1` will return address of `20 + 1` memory after the first element (not that the size of `str` is `20`). 


### Offset

`offsetof(TYPE, MEMBER)` returns `size_t` of the _MEMBER_ offset from initial position of a _TYPE_. If we have the struct below for example:

```c
typedef struct Example {
    int x; // 4 bytes
    char y; // 1 byte
    // 3 bytes pad
    int z; // 4 bytes
} Example;
```

We can get `offsetof(Example, y)` which will be equal to `4`. We can also get offset of nested members from a nested struct by using `.` delimiter to move between members.

file: [memory_management_2.c](files/memory_management_2.c)
video: https://www.youtube.com/watch?v=txf92femaGM


### Difference between memmove and memcpy

`memmove` is safe to use when you have overlapping memory between the source and destination. It will first copy the source into a buffer and then replace the destination. But `memcpy` is not safe _(in some compilers)_ for copying overlapping memory since it doesn't first copy the memory into a buffer.

video: https://www.youtube.com/watch?v=nFl1cNXk85s


### Double pointer (or more!)

They are just pointers to another pointer. We can derefrence them (get the value) using a astricks, and you need (N-1) astricks where N is number of pointers.

Example:

```c
void display(char********* output) {
    printf("%s\n", *output);
}

int main(int argc, char* argv[]) {
    char* str = "This is a test";
    char** str2 = &str;
    char*** str3 = &str2;
    char**** str4 = &str3;
    char***** str5 = &str4;
    char****** str6 = &str5;
    char******* str7 = &str6;
    char******** str8 = &str7;
    char********* str9 = &str8;
    
    display(str9);
    return 0;
}
```

_Why to use double pointer at all?_ The nice part of it is that you can change the value we are pointing at.


### Why is it useful to hexadecimal to represent memory

Since hexadecimal is 2 to the power of 4, and binary is base 2, we can easily imagine representation of a hexadecimal number by extracting each digit and representing it as binary.

For example:

- Binary representation of number 23 is `00010111`
- The hexadecimal value is `17`
- Extract each digit of hexadecimal value, so we have `{1, 7}` and represent each digit as binary, so we have: `{0001, 0111}`, and merge them together to have a single byte: `00010111`.


Video: https://www.youtube.com/watch?v=lvjW-aUcbF0
file: [operators_1.c](files/operators_1.c)

### const

I already understand const. The only note: The valid way to use it for a pointer is to use it after the pointer:

```c
int * const x = &n;
```

The code below is a pointer to a constant int:

```c
const int *x;
```

## Operators

### bit-shift operation

- `Left shift`

It takes a binary number and moves it to left for one bit (filling the remaining with 0). So if `int a = 5` and 5 is `0101` in binary, `a << 1` will result in: `1010` which is 10. Doing it again gives us 20, 40, 80, ...  so all in all it multiplies a number by 2. If we shift too much, the binary numbers can disapear and get out of boundry and can even go over the sign bit and make the number negative.

- `Right shift`

Same thing happens with right shift. The number will be devided by 2. **The right shift takes a look at sign bit** and fills the shifted bits with sign bit (in most compilers).

### Bitwise operators

Well they simply apply `and`/`or`/`xor`/`not` operations at bit level!

```
5   ->   0 1 0 1
9   ->   1 0 0 1

5&9 ->   0 0 0 1   -> 1
5|9 ->   1 1 0 1   -> 13
5^9 ->   1 1 0 0   -> 12   (XOR)
```

```
5   ->   0 1 0 1
~5  ->   1 0 1 0

9   ->   1 0 0 1
~9  ->   0 1 1 0 
```

#### Practical example: flag system

If we assume we want to store 32 flags in a single int, since an int has 32 bits then we can use each bit as a on/off flag.

If we want to see the "first" flag is "ON/true", we can do a bitwise & operation of the number with `1` and assure its not 0;
Or generally:

> If we want to see the nth flag is "ON/true", we can do a bitwise & operation of the number with n in binary and assure its not 0;

Additionally, to enable flags on the `int` number we had, we can use bitwise or operation between binary representation of numbers to turn on those flags (bits): `unsigned int flag = 0b1 | 0b10 | 0b1001`.

The code example explains it even better.

file: [operators_2.c](files/operators_2.c)
video: https://www.youtube.com/watch?v=6hnLMnid1M0


## UNIX

- [Process](unix/UNIX_PROCESS.md)
- [Threads](unix/UNIX_THREAD.md)
---


## Resources (+Additional)

- (Binary Numbers and Data Representation)[https://www.youtube.com/playlist?list=PLbtzT1TYeoMgzLyE9n-pJrTFZX18EUKw_]
- (Code Vault)[https://code-vault.net]
- (Signed representation of binary numbers)[https://youtu.be/-CEJXDeDsAQ?si=OeG2PcYKywU-uU9q&t=692]
