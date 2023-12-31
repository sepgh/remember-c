#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *args[]){
	int arr1[] = {1, 2};
	int arr2[] = {1, 2};
	
	memset(arr1, 0, 2 * sizeof(int));
	printf("%d %d \n", arr1[0], arr1[1]);
	
	memset(arr1, 1, 2 * sizeof(int));
	printf("%d %d \n", arr1[0], arr1[1]);
	printf("%08x %08x \n", arr1[0], arr1[1]);
	// memset accepted bytes in and not bits.

	return 0;
}
