#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main () {
	int s, b, i;
	while (scanf("%i %i%*c", &s, &b) != EOF) {
		if (s == 0 && b == 0) break;

		int *izquierda = (int*)malloc((s + 1)*sizeof(int));
		int *derecha = (int*)malloc((s + 1)*sizeof(int));

		for (i = 1; i < (s + 1); i++) {
			izquierda[i] = i - 1;
			derecha[i] = i + 1;
		}

		int inf, sup;
		while(b--) {
			scanf("%i %i%*c", &inf, &sup);

			if (izquierda[inf] != 0) printf("%i ", izquierda[inf]);
			else printf("* ");
			if (derecha[sup] != (s + 1)) printf("%i\n", derecha[sup]);
			else printf("*\n");
			derecha[izquierda[inf]] = derecha[sup];
			izquierda[derecha[sup]] = izquierda[inf];			
		}
		puts("-");
	}
	return 0;
}