#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	int caracteres [256];

	int n;
	while (scanf("%i%*c", &n) != EOF) {
		while (n) {
			memset(caracteres, 0, sizeof(caracteres));
			int k ;
			scanf("%i%*c", &k);
			unsigned char car;
			int val;
			while (k) {
				scanf ("%c %i%*c", &car, &val);
				caracteres[car] = val;
				k --;
			}

			int m;
			scanf("%i%*c", &m);
			int pago = 0;
			while (m && scanf("%c", &car) != EOF) {
				if (car == '\n') {
					m --;
					continue;
				}
				
				pago += caracteres[car];
				
			}
			printf("%d.%02d$\n", pago / 100, pago % 100);
			n --;
		}
	}
	
	return 0;
}