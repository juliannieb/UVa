#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main () {
	int N, P;
	vector <int> places;
	while (scanf("%i%*c", &N) == 1) {
		while (N--) {
			scanf("%i%*c", &P);
			places = vector <int>();
			int menor = 1000;
			for(int i = 0; i < P; i++) {
				int cont = 0;
				char c = ' ';
				int n;
				while (scanf("%i%c", &n, &c) == 2 && c == ' ') {
					cont++;
				}
				if (cont == menor) {
					places.push_back(i + 1);
				} else if (cont < menor) {
					menor = cont;
					places = vector <int>();
					places.push_back(i + 1);
				}
			}
			printf("%i", places[0]);
			for(int i = 1; i < places.size(); i++) {
				printf(" %i", places[i]);
			}
			printf("\n");
			getchar();
		}
	}
	return 0;
}