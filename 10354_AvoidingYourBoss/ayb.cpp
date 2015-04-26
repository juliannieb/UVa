#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1000000;

int main () {
	int P, R, BH, OF, YH, M;
	while (scanf("%i %i %i %i %i %i%*c", &P, &R, &BH, &OF, &YH, &M) == 6) {
		int roads_boss[110][110];
		int roads_me[110][110];

		for (int i = 0; i < 110; i++) {
			for (int j = 0; j < 110; j++) {
				roads_boss[i][j] = roads_me[i][j] = INF;
			}
			roads_boss[i][i] = roads_me[i][i] = 0;
		}

		int a, b, cost;
		for (int i = 0; i < R; i++) {
			scanf("%i %i %i%*c", &a, &b, &cost);
			roads_boss[a][b] = roads_boss[b][a] = cost;
			roads_me[a][b] = roads_me[b][a] = cost;
		}

		for (int k = 1; k <= P; k++) {
			for (int i = 1; i <= P; i++) {
				for (int j = 1; j <= P; j++) {
					roads_boss[i][j] = min(roads_boss[i][j], roads_boss[i][k] + roads_boss[k][j]);
				}
			}
		}

		int path[110] = {};
		for (int k = 1; k <= P; k++) {
			if (roads_boss[BH][OF] == roads_boss[BH][k] + roads_boss[k][OF]) {
				path[k] = 1;
			}
		}

		for (int k = 1; k <= P; k++) {
			if (path[k] == 0) {
				for (int i = 1; i <= P; i++) {
					if (path[i] == 0) {
						for (int j = 1; j <= P; j++) {
							if (path[j] == 0) {
								roads_me[i][j] = min(roads_me[i][j], roads_me[i][k] + roads_me[k][j]);
							}
						}
					}
				}
			}
		}
		
		if (roads_me[YH][M] != 1000000 && path[YH] == 0 && path[M] == 0) printf("%i\n", roads_me[YH][M]);
		else printf("MISSION IMPOSSIBLE.\n");

	}
	return 0;
}