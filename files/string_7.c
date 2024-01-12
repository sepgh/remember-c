#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getString(char* str) {
	strcpy(str, "test");
}


int main(int argc, char *args[]){
	char s[50];
	getString(s);
	s[0] = 'p';  // Cant do without passing the s to func, works with passing
	// free(s);  // Cant do either for same reason
	
	printf("%s\n", s);
	return 0;
}
