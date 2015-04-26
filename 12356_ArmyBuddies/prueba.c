#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


int main () {
	int arr[10];
	memset(arr, 0, sizeof(arr));

	int i;
	for (i = 0; i < 10; i++){
		printf("%i\n", arr[i]);
	}

	return 0;
}