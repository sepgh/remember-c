#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *args[]){

	char text1[50];
	char text2[] = "temp";
	char text3[] = "Hello world";

	// strcpy(text1, text3);
	strncpy(text1, text3, 17);

	printf("%s \n%s \n%s \n", text1, text2, text3);
	

}
