#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

static double const C = 12.01;
static double const H = 1.008;
static double const O = 16.00;
static double const N = 14.01;

int main () {
	int t;
	scanf("%i%*c", &t);
	while (t--) {
		char s[80];
		double suma_total;
		suma_total = 0.0;
		int n;
		n = 1;
		double valor;
		if (scanf("%s", &s) == 1) {
			for (int i = 0; i < strlen(s); i++) {
				if (isalpha(s[i])) {
					if (s[i] == 'C') valor = C;
					else if (s[i] == 'H') valor = H;
					else if (s[i] == 'O') valor = O;
					else if (s[i] == 'N') valor = N;

					if(i + 1 < strlen(s)) {
						if (!isalpha(s[i + 1])) {
							n = s[i + 1] - 48;
							if (i + 2 < strlen(s)) {
								if (!isalpha(s[i + 2])) {
									n = (n * 10) + (s[i + 2] - 48);
								}
							}
						}
					}
					suma_total += valor * n;
					n = 1;
				}
			}
		}
		printf("%.3lf\n", suma_total);
	}
	return 0;
}