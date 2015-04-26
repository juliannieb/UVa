#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main () {
	int N, P;
	queue <int> places;
	while (scanf("%i%*c", &N) == 1) {
		while (N--) {
			scanf("%i%*c", &P);
			places = queue <int>();
			int menor = 1000;
			for(int i = 0; i < P; i++) {
				int cont = 0;
				char c = ' ';
				int n;
				while (scanf("%i%c", &n, &c) == 2 && c == ' ') {
					cont++;
				}
				if (cont == menor) {
					places.push(i + 1);
				} else if (cont < menor) {
					menor = cont;
					places = queue <int>();
					places.push(i + 1);
				}
			}
			if (!places.empty()) {
				printf("%i", places.front());
				places.pop();
			}
			while (!places.empty()) {
				printf(" %i", places.front());
				places.pop();
			}
			printf("\n");
			getchar();
		}
	}
	return 0;
}