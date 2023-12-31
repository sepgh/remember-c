#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *args[]){
	char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	//char str[] = "Hello";
	printf("%s \n", str);

	str[0] = 'h';
	printf("%s \n", str);


	char* str2 = "Hello";
	printf("%s \n", str2);
	
	// BUT CANT MODIFY LIKE BEFORE, BELOW LINE WILL GET SEGMENTATION FAULT
	str2[0] = 'h';

	return 0;
}
