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
	char nombre2[25]:
	while (scanf("%s\n", &nombre1) != EOF) {
		scanf("%s\n", &nombre2);
		int i = 0;
		int valor_nombre1 = 0;
		while (nombre1[i] != '\0') {
			if (isalpha(nombre1[i])) {
				valor_nombre1 += toupper(nombre1[i]) - 64;
			}
		}
		int valor_nombre2 = 0;
		while (nombre2[i] != '\0') {
			if (isalpha(nombre2[i])) {
				valor_nombre2 += toupper(nombre2[i]) - 64;
			}
		}
		valor_nombre1 = descompone(valor_nombre1);
		valor_nombre2 = descompone(valor_nombre2);
		printf("1. %i\n", valor_nombre1);
		printf("2. %i\n", valor_nombre2);
	}
	return 0;
}