#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main () {
	int field_number = 1;
	int n, m;
	while (scanf("%i %i%*c", &n, &m) == 2) {
		if (n == 0 && m == 0) break;
		if (field_number == 1) printf("Field #1:\n");
		else printf("\nField #%i:\n", field_number);
		vector < vector < int > > field (n, vector < int > (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%c", &field[i][j]);
			}
			scanf("%*c");
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] != '*') {
					int cont = 0;
					for (int k = i - 1; k <= i + 1; k++) {
						for (int p = j - 1; p <= j + 1; p++) {
							if ((k >= 0 && k < n) && (p >= 0 && p < m)) {
								if (field[k][p] == '*') cont++;
							}
						}
					}
					printf("%i", cont);
				}else printf("*");
			}
			printf("\n");
		}
		field_number++;
	}
	return 0;
}