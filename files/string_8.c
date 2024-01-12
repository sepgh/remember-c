#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getString(char* str) {
	strcpy(str, "test");
}


int main(int argc, char *args[]){
	char str[] = "Let's break this string into pieces";
	

	// Returns a char* to next occurrence of each piece
	// Also modifies the input (str) and adds "String terminator character" at each piece
	char* piece = strtok(str, " ");
	// now value of str is actually: "Let's\000break this string into pieces";
	printf("%s\n", piece);

	piece = strtok(NULL, " ");
	printf("%s\n", piece);


	printf("-------------\n");
	
	
	
	char str2[] = "Let's break this string into pieces";
	
	piece = strtok(str2, " ");
	while(piece != NULL){
		printf("%s\n", piece);
		piece = strtok(NULL, " ");
	}

	return 0;
}
