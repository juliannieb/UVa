#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool ordenar_tesoro (pair <pair <int, int>, int> i, pair <pair <int, int>, int> j) { return (i.first.second < j.first.second); }
bool ordenar_encontrados (pair <pair <int, int>, int> i, pair <pair <int, int>, int> j) { return (i.second < j.second); }

int main () {
	int t, w;
	int cont = 0;
	while (scanf("%i %i%*c", &t, &w) == 2) {
		int n;
		scanf("%i%*c", &n);
		vector < pair < pair <int, int >, int > > treasures(n);
		for (int i = 0; i < n; i++) {
			scanf("%i %i%*c", &treasures[i].first.first, &treasures[i].first.second);
			treasures[i].second = i;
		}
		sort (treasures.begin(), treasures.end(), ordenar_tesoro);
		vector < pair < pair<int, int>, int > > encontrados;
		int total = 0;
		for (int i = treasures.size() - 1; i >= 0; i--) {
			int costo = (w * treasures[i].first.first) + (2 * w * treasures[i].first.first);
			if (costo <= t) {
				encontrados.push_back(treasures[i]);
				t -= costo;
				total += treasures[i].first.second;
			}
		}
		if (cont > 0) printf("\n");
		sort (encontrados.begin(), encontrados.end(), ordenar_encontrados);
		printf("%i\n%i\n", total, encontrados.size());
		for (int i = 0; i < encontrados.size(); i++) {
			//if (encontrados[i].first.first != 0) {
				printf("%i %i\n", encontrados[i].first.first, encontrados[i].first.second);	
			//}
		}
		cont ++;
		getchar();
	}
	return 0;
}