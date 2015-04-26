#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;

vi numeros;
vi best, prev;

void back_track (int indice) {
	if (numeros[prev[indice]] == numeros[indice]) {
		printf("%i\n", numeros[indice]);
		return;
	}
	back_track(prev[indice]);
	printf("%i\n", numeros[indice]);
}

int main () {
	int n;
	while (scanf("%i%*c", &n) == 1) {
		numeros.push_back(n);
	}
	best = vi(numeros.size(), 1);
	prev = vi(numeros.size());
	for (int i = 0; i < numeros.size(); i++) {
		prev[i] = i;
	}
	int max = 1;
	int indice_max = 0;
	for (int i = 1; i < numeros.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (numeros[j] < numeros[i] && best[j] + 1 > best[i]) {
				best[i] = best[j] + 1;
				prev[i] = j;
				if (best[i] > max) {
					max = best[i];
					indice_max = i;
				}
			}
		}
	}
	printf("%i\n-\n", max);
	back_track(indice_max);
	return 0;
}