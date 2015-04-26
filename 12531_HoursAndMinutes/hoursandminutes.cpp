#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int a[185] = {};

int main () {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 60; j += 2) {
			int angulo_min = abs((i * 30) - ((j / 5.0) * 30));
			angulo_min = min(angulo_min, 360 - angulo_min);
			a[angulo_min] = 1;
		}
		
	}
	for (int i = 0; i <= 180; i++) {
		printf("%i, ", a[i]);
	}
	int n;
		while (scanf("%i%*c", &n) == 1) {
			if (a[n] == 1) printf("Y\n");
			else printf("N\n");
		}
	return 0;
}