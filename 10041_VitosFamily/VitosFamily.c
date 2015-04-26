#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insertion_sort (int * street_numbers, int contador) {
	int key, j, i;
	for (i = contador - 1; i < contador; i++) {
		key = street_numbers[i];
		j = i - 1;
		while (j >= 0 && street_numbers[j] > key) {
			street_numbers[j + 1] = street_numbers[j];
			street_numbers[j] = key;
			j--;
		}
	}
}

int sum_distances (int * street_numbers, int contador, int optimal_house) {
	int i;
	int sum = 0;
	for (i = 0; i < contador; i ++) {
		sum += abs(optimal_house - street_numbers[i]);
	}
	return sum;
}

int optimal_house (int * street_numbers, int contador) {
	int media;
	media = street_numbers[(contador - 1) / 2];
	return media;
}

int main () {
	int test_cases;
	while (scanf("%i%*c", &test_cases) != EOF) {
		while (test_cases) {
			int street_numbers[30000];
			int contador = 0;
			char caracter;
			int number_of_streets;

			scanf("%i%*c", &number_of_streets);

			while (number_of_streets) {
				scanf("%i%*c", &street_numbers[contador]);
				contador ++;
				insertion_sort(street_numbers, contador);
				number_of_streets --;
			}
			int opt_house = optimal_house (street_numbers, contador);
			printf("%i\n", sum_distances(street_numbers, contador, opt_house));
			test_cases --;
		}
		
	}
	return 0;
}