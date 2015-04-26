#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1000000

int fw[110][110];

int main () {
	int t;
	scanf("%i%*c", &t);
	for (int cases = 1; cases <= t; cases++) {
		int n;
		int r;
		scanf("%i%*c%i%*c", &n, &r);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) fw[i][j] = 0;
				else fw[i][j] = INF;
			}
		}
		int a, b;
		while (r--) {
			scanf("%i %i%*c", &a, &b);
			fw[a][b] = 1;
			fw[b][a] = 1;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
				}
			}
		}
		int s, d;
		scanf("%i %i%*c", &s, &d);
		int t_time = 0;
		for (int i = 0; i < n; i++) {
			if (fw[s][i] != INF && fw[i][d] != INF) {
				t_time = max(t_time, fw[s][i] + fw[i][d]);
			}
		}
		printf("Case %i: %i\n", cases, t_time);
	}
	return 0;
}