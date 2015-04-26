#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;

vi disjoint;

void init (int size) {
	disjoint.resize(size);
	for (int i = 0; i < size; i++) {
		disjoint[i] = i;
	}
}

int find_set (int i) {
	if (disjoint[i] == i) return i;
	else return (disjoint[i] = find_set(disjoint[i]));
}

bool is_same (int i, int j) {
	return (find_set(i) == find_set(j));
}

void union_set (int i, int j) {
	disjoint[find_set(i)] = find_set(j);
}

int main () {
	int t;
	scanf("%i%*c", &t);
	getchar();
	char linea[200];
	char c;
	for (int i = 0; i < t; i++) {
		if (i) printf("\n");
		int n;
		scanf("%d%*c", &n);
		int comp_a, comp_b;
		int succ, unsucc;
		init(n);
		succ = 0;
		unsucc = 0;
		while (gets(linea) && strlen(linea) != 0) {
			sscanf(linea, "%c %d %d%*c", &c, &comp_a, &comp_b);
			if (c == 'c') union_set(comp_a - 1, comp_b - 1);
			else {
				if (is_same(comp_a - 1, comp_b - 1)) succ++;
				else unsucc++;
			}
		}
		printf("%d,%d\n", succ, unsucc);
	}
	return 0;
}