#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Declaring array of strings
int main(int argc, char *args[]){
	// Way 1
	char array[3][50];

	// string copy
	strcpy(array[0], "Hello World");
	strcpy(array[1], "Hello World 2");
	strcpy(array[2], "Hello World 3");

	printf("Strings are: \n%s \n%s \n%s \n", array[0], array[1], array[2]);


	// Way 2
	char array2[3 * 50];
	strcpy(array2, "Hello World");
	strcpy(array2 + 50, "Hello World 2");
	strcpy(array2 + 100, "Hello World 3");

	printf("Strings are: \n%s \n%s \n%s \n", array2, array2 + 50, array2 + 100);


	// Way 3
	char array3[][50] = {
		"Hello World", "test", "123"
	};

	printf("Strings are: \n%s \n%s \n%s \n", array3[0], array3[1], array3[2]);


	return 0;
}
