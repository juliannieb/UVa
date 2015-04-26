#include <stdio.h>
#include <stdlib.h>

int main () {
	long int n;
	long int *ages;
	long int i;
	while (scanf("%i%*c", &n) != EOF) {
		ages = (long int*)malloc(n*sizeof(long int));
		for (i = 0; i < n; i ++) {
			scanf("%i%*c", &ages[i]);
		}
		
	}
}