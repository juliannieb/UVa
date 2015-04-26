#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	int n;
	printf("PERFECTION OUTPUT\n");
	while (scanf("%i%*c", &n) != EOF) {
		if (n == 0) break;
		n = fabs(n);
		int x = n / 2;
		int suma = 0;
		while (x > 0) {
			if (n % x == 0) suma += x;
			x--;
		}
		if (suma == n) printf("%5i  PERFECT\n", n);
		else if (suma < n) printf("%5i  DEFICIENT\n", n);
		else printf("%5i  ABUNDANT\n", n);
	}
	printf("END OF OUTPUT\n");
	return 0;
}