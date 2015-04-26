#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool ordena (int i, int j) { return (i < j); }

int main () {
	int T;
	scanf("%i%*c", &T);
	while (T--) {
		int N, M;
		scanf("%i %i%*c", &N, &M);
		vector <int> list_a (N);
		vector <int> list_b (M);
		for (int i = 0; i < N; i++) {
			scanf("%i%*c", &list_a[i]);
		}
		for (int i = 0; i < M; i++) {
			scanf("%i%*c", &list_b[i]);
		}
		sort (list_a.begin(), list_a.end(), ordena);
		sort (list_b.begin(), list_b.end(), ordena);
		vector<int> v (N + M);
  		vector<int>::iterator it;
		it = set_intersection (list_a.begin(), list_a.end(), list_b.begin(), list_b.end(), v.begin());
		v.resize(it-v.begin());
		int cambiados = (N + M) - (v.size() * 2);
		printf("%i\n", cambiados);
	}
	return 0;
}