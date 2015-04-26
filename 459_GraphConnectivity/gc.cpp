#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main () {
	int t;
	scanf("%i%*c", &t);
	char max_node;
	while (t--) {
		scanf("%*c%c%*c", &max_node);
		int cont = max_node - 64;
		vector < set <char> > edges (max_node - 64, set <char> ());
		for(int i = 65; i <= max_node; i++) {
			set <char> temp;
			temp.insert(i);
			edges[i - 65] = temp;
		}
		char nodo1, nodo2;
		while(scanf("%c", &nodo1) == 1) {
			if (nodo1 == '\n') break;
			scanf("%c%*c", &nodo2);
			int flag1 = 0;
			int flag2 = 0;
			int encontrado1 = -1;
			int encontrado2 = -1;
			for (int i = 0; i < max_node - 64; i++) {
				if (edges[i].find(nodo1) != edges[i].end()) {
					flag1 = 1;
					encontrado1 = i;
				}
				if (edges[i].find(nodo2) != edges[i].end()) {
					flag2 = 1;
					encontrado2 = i;
				}
				if (flag1 && flag2) break;
			}
			
			if (flag1 && flag2 && (encontrado1 != encontrado2)) {
				set_union(edges[encontrado1].begin(), edges[encontrado1].end(), edges[encontrado2].begin(), edges[encontrado2].end(), inserter(edges[encontrado1], edges[encontrado1].begin()));
				edges[encontrado2] = set <char> ();
				cont--;
			}else if (flag1) {
				edges[encontrado1].insert(nodo2);
			}else if (flag2) {
				edges[encontrado2].insert(nodo1);
			}
		}
		printf("%i\n\n", cont);
	}
	return 0;
}