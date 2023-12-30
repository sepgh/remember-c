#include <stdio.h>
#include <stdlib.h>

void printBytes(int* arr, int n){
	int i;
	for (i = 0; i < n; i++){
		//  %x says print it in hexadecimal format
		//  and print it on 8 characters
		//  and print zeros when you dont have anything to show
		printf("%08x ", arr[i]);  // This is derefrencing the pointer, like *(arr + i)
	}
	printf("\n");
}


void printBytesAny(void* arr, int n){
	int i;
	
	for (i = 0; i < n; i++){
		// We can not derefrence a void pointer anymore, so cant use arr[i]
		// So we first derefrence and convert it into charpointer:  ((char*) arr)[i])
		// If we are printing one since byte it means we are printing 2 base-16 digits
		printf("%02x ", ((char*) arr)[i]);
	}

	printf("\n");
}



int main(int argc, char *args[]){
	int arr[] = {16, 31, 32, 65};
	printBytes(arr, 4);

	long long arr2[] = {16, 31, 32, 65};
	// printBytes(arr2, 4);  // Unexpected results  CANT EVEN RUN THIS UNLIKE IN THE VIDEO
	printBytesAny(arr2, 4 * sizeof(long long));
	printBytesAny(arr, 4 * sizeof(int));

	return 0;
}
