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


## Memory manipulation

Functions (all work on arrays):

- `memcmp`: memory comparing
- `memcp`: memory copy
- `memset`: set value in memory
- `memchr`: find byte in memory

Video: https://www.youtube.com/watch?v=ypG9W33LOTk

Files: [memory_manipulation.c](files/memory_manipulation.c)  [memory_manipulation_2.c](files/memory_manipulation_2.c)  [memory_manipulation_3.c](files/memory_manipulation_3.c)  [memory_manipulation_4.c](files/memory_manipulation_4.c) 



