#include <cstdio>

using namespace std;

int digits[6005];

int main () {
	int cont = 0;

	cont = 0;
	for (int i = 0; i < 10; i++) {
		cont++;
		digits[i] = cont;
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int num = (i * 10) + j;
			if (i != j) {
				cont++;
				digits[num] = cont;
			}
			else
				digits[num] = cont;
		}
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				int num = (((i * 10) + j) * 10) + k;
				if (i != j && i != k && j != k) {
					cont ++;
					digits[num] = cont;
				}
				else
					digits[num] = cont;
			}
		}
	}

	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int m = 0; m < 10; m++) {
					int num = ((((((i * 10) + j) * 10) + k) * 10) + m);
					if (i != j && i != k && i != m && j != k && j != m && k != m) {
						cont++;
						digits[num] = cont;
					}
					else
						digits[num] = cont;
				}
			}
		}
	}

	int a, b;
	while (scanf("%i %i%*c", &a, &b) == 2) {
		int ans = digits[b] - digits[a - 1];
		printf("%i\n", ans);
	}


	return 0;
}