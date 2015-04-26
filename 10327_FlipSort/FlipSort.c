#include <stdio.h>
#include <stdlib.h>

int insertion_sort(int *numeros, int n) {
	int key, j, i;
	int contador = 0;
	for (i = n - 1; i < n; i++) {
		key = numeros[i];
		j = i - 1;
		while (j >= 0 && numeros[j] > key) {
			numeros[j + 1] = numeros[j];
			numeros[j] = key;
			j--;
			contador ++;
		}
	}
	return contador;
}
int main () {
	int n;
	while (scanf("%i%*c", &n) != EOF) {
		int i;
		int numeros[n];
		int contador = 0;
		for (i = 0; i < n; i ++) {
			scanf("%i%*c", &numeros[i]);
			contador += insertion_sort(numeros, i + 1);
		}
		printf("Minimum exchange operations : %i\n", contador);
	}
	return 0;
}