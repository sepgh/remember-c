#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *args[]){

	char str[] = "Hello, friend!";

	// strchr returns null if char not found otherwise returns pointer to the found value
	// char *result = strchr(str, ',');
	
	// strrchr works in reverse and looks from last to first
	char *result = strrchr(str, 'e');


	// string char
	if (result){
		printf("Character was found \n");
		printf("Position: %d\n", result - str);
	} else {
		printf("Character was not found \n");
	}


	return 0;

}
