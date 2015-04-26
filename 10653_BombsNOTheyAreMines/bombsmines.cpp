#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int dist[1005][1005];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

int num_rows, num_columns;

void bfs (int start_row, int start_column) {
	queue <ii> q;
	q.push(ii(start_row, start_column));
	dist[start_row][start_column] = 0;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < num_rows && nc >= 0 && nc < num_columns) {
				if (dist[nr][nc] == -1) {
					dist[nr][nc] = dist[r][c] + 1;
					q.push(ii(nr, nc));
				}
			}
		}
	}
}

int main () {
	while (scanf("%i %i", &num_rows, &num_columns) == 2) {
		if (num_rows == 0 && num_columns == 0) break;

		for (int i = 0; i < num_rows; i++) {
			for (int j = 0; j < num_columns; j++) {
				dist[i][j] = -1;
			}
		}
		
		int n;
		scanf("%i", &n);

		int bomb_row;
		int bombs;
		int bomb_column;
		while (n--) {
			scanf("%i %i", &bomb_row, &bombs);
			
			while (bombs--) {
				scanf("%i", &bomb_column);
				dist[bomb_row][bomb_column] = -2;
			}
		}

		int start_row, start_column, dest_row, dest_column;
		scanf("%i %i%*c%i %i%*c", &start_row, &start_column, &dest_row, &dest_column);
		bfs(start_row, start_column);
		printf("%i\n", dist[dest_row][dest_column]);

	}
	return 0;
}