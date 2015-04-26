#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int descompone (int n) {
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	while (res >= 10) {
		n = res;
		res = 0;
		while (n > 0) {
			res += n % 10;
			n /= 10;
		}
	}
	return res;
}

int main () {
	char nombre1[25];
	char nombre2[25];
	while (gets(nombre1)) {
		gets(nombre2);
		int i = 0;
		int valor_nombre1 = 0;
		while (nombre1[i] != '\0') {
			if (isalpha(nombre1[i])) {
				valor_nombre1 += toupper(nombre1[i]) - 64;
			}
			i++;
		}
		i = 0;
		int valor_nombre2 = 0;
		while (nombre2[i] != '\0') {
			if (isalpha(nombre2[i])) {
				valor_nombre2 += toupper(nombre2[i]) - 64;
			}
			i++;
		}
		valor_nombre1 = descompone(valor_nombre1);
		valor_nombre2 = descompone(valor_nombre2);
		if (valor_nombre1 <= valor_nombre2) {
			printf("%.2f %%\n", (valor_nombre1 / (float)valor_nombre2) * 100);
		}
		else printf("%.2f %%\n", (valor_nombre2 / (float)valor_nombre1) * 100);
	}
	return 0;
}