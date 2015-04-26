#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main () {
	int n;
	while (scanf("%i%*c", &n) != EOF) {
		while (n--) {
			int k ;
			scanf("%i%*c", &k);
			char car;
			int val;
			map <char, int> caracteres;
			while (k--) {
				scanf ("%c %i%*c", &car, &val);
				caracteres[car] = val;
			}

			int m;
			scanf("%i%*c", &m);
			int pago = 0;
			while (m--) {
				while (scanf("%c", &car) == 1) {
					if (car == '\n') break;
					pago += caracteres[car];
				}			
			}
			printf("%d.%02d$\n", pago / 100, pago % 100);
		}
	}
	return 0;
}