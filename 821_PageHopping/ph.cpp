#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>

#define INF 1000000

using namespace std;

int matriz [100][100];

void floyd_warshal (int max) {
	for (int k = 0; k < max; k++) {
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				matriz[i][j] = min(matriz[i][j], matriz[i][k] + matriz[k][j]);
			}
		}
	}
}

float promedio (int max) {
	int suma = 0;
	int cont = 0;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if (matriz[i][j] != INF && i != j) {
				suma += matriz[i][j];
				cont++;
			}
		}
	}
	return ((float)suma / cont);
}

void inicia_matriz () {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == j) matriz[i][j] = 0;
			else matriz[i][j] = INF;
		}
	}
}

int main () {
	int a, b;
	bool haycaso = false;
	inicia_matriz();
	int max = -1;
	int test_case = 1;
	while (scanf("%i %i", &a, &b) == 2) {
		if ((!a && !b) && !haycaso) break;
		if (!a && !b) {
			floyd_warshal(max);
			printf("Case %i: average length between pages = %.3f clicks\n", test_case, promedio(max));
			test_case++;
			max = -1;
			inicia_matriz();
			haycaso = false;
		}
		else {
			haycaso = true;
			if (a > max) max = a;
			else if (b > max) max = b;
			matriz[a - 1][b - 1] = 1;
		}
	}
	return 0;
}