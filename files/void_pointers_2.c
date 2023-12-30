#include <stdio.h>


int main(){
	
	int value = 65;

	int* i = &value;
	
	printf("Decimal: %d \n", *i);
	printf("Hex: %x \n", *i);
	printf("Hex 2: %08x \n", *i);
	printf("Char: %c \n", *i);
	printf("Converted Char: %c \n", (char) *i);

	char c = (char) *i;
	
	printf("Char Hex: %x \n", c);
	printf("Char Hex 2: %08x \n", c);
	printf("Char Hex 3: %02x \n", c);


	long long a = 65;
	char c2 = (char) a;

	printf("Char Hex 2: %08x \n", c2);
	printf("Char Hex 3: %02x \n", c2);
	


	printf("------------- \n");


	int int_arr[] = {65, 70, 80};
	
	printf("arr: %d\n", *int_arr);
	printf("arr [0]: %d\n", *(int_arr + 0));
	printf("arr [1]: %d\n", *(int_arr + 1));
	
	printf("------------- \n");


	char* char_arr = (char*) int_arr;

	printf("arr: %d\n", *char_arr);
	printf("arr[0]: %d\n", *(char_arr + 0));
	printf("arr[1]: %d   [NOT WHAT YOU EXPECT, 70]\n", *(char_arr + 1));
	printf("arr[4]: %d   [ONE THAT YOU EXPECT] \n", (char_arr)[4]);
	printf("arr[0] hex: %08x\n", *(char_arr + 0));
	
	printf("arr[0] hex 2 p 0: %02x\n", (char_arr)[0]);
	printf("arr[0] hex 2 p 1: %02x\n", (char_arr)[1]);
	printf("arr[0] hex 2 p 2: %02x\n", (char_arr)[2]);
	printf("arr[0] hex 2 p 3: %02x\n", (char_arr)[3]);
	
	
	printf("arr[1] hex: %08x\n", *(char_arr + 1));
	printf("arr[1] hex 2 p 0: %02x\n", (char_arr)[4]);
	printf("arr[1] hex 2 p 1: %02x\n", (char_arr)[5]);
	printf("arr[1] hex 2 p 2: %02x\n", (char_arr)[6]);
	printf("arr[1] hex 2 p 3: %02x\n", (char_arr)[7]);
	


}


