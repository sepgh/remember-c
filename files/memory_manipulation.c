#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *args[]){
	int arr1[] = {1, 2};  // 0 0 0 1
	//int arr2[] = {1, 2};
	int arr2[] = {1 , 3};

	// Similar to strcmp to compare two arrays
	// Takes in void pointers
	int comparison = memcmp(arr1, arr2, 2 * sizeof(int));
	
	if (comparison == 0) {
		printf("Arrays are the same \n");
	} else {
		printf("Arrays are not the same \n");
	}


	// If you compare two different types of array you have to pass in the size of the shortest one
	
	short int arr3[] = {1,2};  // 0 1
	comparison = memcmp(arr1, arr3, 2 * sizeof(short));

	if (comparison == 0) {
		printf("Arrays are the same \n");
	} else {
		printf("Arrays are not the same \n");  // <--
		// Arrays are not the same because the types are different
	}

	return 0;
}
