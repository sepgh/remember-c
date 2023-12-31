#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *args[]){
	int arr1[] = {3, 4};
	int arr2[] = {1, 2};

	memcpy(arr1, arr2, 2*sizeof(int));  // destination, source, how much
	
	printf("%d %d\n", arr1[0], arr1[1]);  // 1 2 from arr2

	return 0;
}
