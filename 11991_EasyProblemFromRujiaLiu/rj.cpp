#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main () {
	int n, m;
	while (scanf("%i%*c%i%*c", &n, &m) == 2) {
		vector < vector <int> > matriz (1000000);
		int num;
		for (int i = 0; i < n; i++) {
			scanf("%i%*c", &num);
			matriz[num - 1].push_back(i + 1);
		}
		int k, v;
		for (int i = 0; i < m; i++) {
			scanf("%i%*c%i%*c", &k, &v);
			if (matriz[v - 1].size() < k) printf("0\n");
			else printf("%i\n", matriz[v - 1][k - 1]);
		}
	}
	return 0;
}