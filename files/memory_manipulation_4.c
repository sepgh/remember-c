#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *args[]){
	int arr1[] = {3, 4};
	int arr2[] = {1, 2};

	// if you want to find a certain byte in array you can use memchr
	// returns pointer to the place of memory where it found the byte
	if (memchr(arr1, 0, sizeof(int) * 2) != NULL) {
		printf("Found the byte \n");
	}

	return 0;
}
