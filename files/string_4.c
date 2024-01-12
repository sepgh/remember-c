#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* str;
int num;

void create(){
	num = 100;
	str = malloc(sizeof(char) * num);
}


void process() {
	char example[100] = "this is a test";
	// Difference between '    str = example   ' and '   strcpy(str, example)   '


	// CASE A which will cause the problem
	// str = example;


	// CASE B
	strcpy(str, example);


	printf("%s\n", str);
}


int main(int argc, char *args[]){

	create();
	process();
	

	// For the case where  str = example  is used in the process function
	// Err:   free(): invalid pointer
	free(str);
	

	return 0;
}
