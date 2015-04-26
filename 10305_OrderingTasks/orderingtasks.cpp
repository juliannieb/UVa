#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<vi> vvi;

vvi graph;
vb visited;
vi toposort;

void topological_sort(int u) {
	visited[u] = true;
	for (int i = 0; i < graph[u].size(); i++) {
		if (!visited[graph[u][i]])
			topological_sort(graph[u][i]);
	}
	toposort.push_back(u + 1);
}

int main () {
	int n, m;
	while (scanf("%i %i%*c", &n, &m) == 2) {
		if (n == 0 && m == 0) break;
		graph = vvi(n);
		visited = vb(n, false);
		toposort = vi();

		int a, b;
		while (m--) {
			scanf("%i %i%*c", &a, &b);
			graph[a - 1].push_back(b - 1);
		}	

		for (int i = 0; i < n; i++) {
			if (!visited[i])
				topological_sort(i);
		}

		for (int i = toposort.size() - 1; i >= 0; i--) {
			printf("%i ", toposort[i]);
		}
		printf("\n");

	}
	return 0;
}