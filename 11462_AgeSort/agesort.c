#include <stdio.h>
#include <stdlib.h>

void quick_sort (long int *ages, long int inicio, long int final) {
	long int i, j, central;
	long int pivote;
	central = (inicio + final) / 2;
	pivote = ages[central];

	i = inicio;
	j = final;

	do {
		while (ages[i] < pivote) i ++;
		while (ages[j] > pivote) j --;

		if (i <= j) {
			long int tmp = ages[i];
			ages[i] = ages[j];
			ages[j] = tmp;
			i ++;
			j --;
		}
	} while (i <= j);

	if (inicio < j) quick_sort(ages, inicio, j);
	if (i < final) quick_sort(ages, i, final);
}

void print_ages(long int *ages, long int n) {
	long int i;
	for (i = 0; i < n - 1; i ++) {
		printf("%ld ", ages[i]);
	}
	printf("%ld\n", ages[n - 1]);
}

int main () {
	long int n;
	long int *ages;
	while(scanf("%ld%*c", &n) != EOF) {
		if (n == 0) break;
		ages = (long int*)malloc(n*sizeof(long int));
		long int i = 0;
		long int aux = n;
		while (n) {
			scanf("%ld%*c", &ages[i]);
			n --;
			i ++;
		}
		quick_sort(ages, 0, aux);
		print_ages(ages, aux);
		free(ages);
	}
	return 0;
}