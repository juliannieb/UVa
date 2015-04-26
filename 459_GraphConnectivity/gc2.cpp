#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main () {
	int t;
	scanf("%i%*c%*c", &t);
	char max_node;
	for (int i = 0; i < t; i++) {
		scanf("%c%*c", &max_node);
		int cont = max_node - 64;
		map <char, set <char> > edges;
		char nodo1;
		char nodo2;
		while(scanf("%c", &nodo1) == 1) {
			if (nodo1 == '\n') break;
			scanf("%c%*c", &nodo2);
			if (edges[nodo1].find(nodo2) == edges[nodo1].end() && edges[nodo2].find(nodo1) == edges[nodo2].end()) {
				edges[nodo1].insert(nodo2);
				edges[nodo2].insert(nodo1);
				set_union(edges[nodo1].begin(), edges[nodo1].end(), edges[nodo2].begin(), edges[nodo2].end(), inserter(edges[nodo1], edges[nodo1].begin()));
				set_union(edges[nodo2].begin(), edges[nodo2].end(), edges[nodo1].begin(), edges[nodo1].end(), inserter(edges[nodo2], edges[nodo2].begin()));
				for (set<char>::iterator it = edges[nodo1].begin(); it != edges[nodo1].end(); it++) {
					char elemento = *it;
					set_union(edges[elemento].begin(), edges[elemento].end(), edges[nodo1].begin(), edges[nodo1].end(), inserter(edges[elemento], edges[elemento].begin()));
				}
				for (set<char>::iterator it = edges[nodo2].begin(); it != edges[nodo2].end(); it++) {
					char elemento = *it;
					set_union(edges[elemento].begin(), edges[elemento].end(), edges[nodo2].begin(), edges[nodo2].end(), inserter(edges[elemento], edges[elemento].begin()));
				}
				cont--;					
			}
		}
		if (i == 0) printf("%i\n", cont);
		else printf("\n%i\n", cont);
	}
	return 0;
}