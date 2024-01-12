#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *args[]){

	char str1[] = "abcd4";
	char str2[] = "abcd1";

	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", strncmp(str1, str2, 4));
	printf("%d\n", memcmp(str1, str2, 4));  // it wont stop at null character and accepts void pointer (accepts anything)
	
	return 0;

}
