#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int books [10005];

bool busqueda_bin (int i, int j, int val) {
	while (i <= j) {
		int mid = (i + j) / 2;
		if (books[mid] == val) return true;
		else {
			if (val < books[mid]) j = mid - 1;
			else i = mid + 1;
		}
	}
	return false;
}

int main () {
	int n;
	int test_case = 0;
	while (scanf("%i%*c", &n) == 1) {
		for (int i = 0; i < n; i++) {
			scanf("%i%*c", &books[i]);
		}
		sort(books, books + n);

		int m;
		scanf("%i%*c%*c", &m);
		int menor_dif = 9999999;
		int book1;
		int book2;
		for (int i = 0; i < n; i++) {
			if (books[i] <= m) {
				if ((abs(books[i] - (m - books[i]))) < menor_dif) {
					if (busqueda_bin(i + 1, n - 1, (m - books[i]))) {
						book1 = books[i];
						book2 = m - books[i];
						menor_dif = abs(books[i] - (m - books[i]));
					}
				}
			}
			else break;
		}
		int aux = book1;
		book1 = min (aux, book2);
		book2 = max (aux, book2);
		printf("Peter should buy books whose prices are %i and %i.\n\n", book1, book2);
		test_case++;
	}
	return 0;
}