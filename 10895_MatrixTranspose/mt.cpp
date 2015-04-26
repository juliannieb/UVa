#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main () {
	int m, n;
	queue<int> positions;
	while (scanf("%i%*c%i%*c", &m, &n) == 2) {
		vector< vector <int> > matrix(m, vector<int> (n, 0));
		int r;
		for (int i = 0; i < m; i++) {
			scanf("%i%*c", &r);
			if (r == 0) {
				scanf("%*c");
				continue;
			}
			int num;
			
			for (int j = 0; j < r; j++) {
				scanf("%i%*c", &num);
				positions.push(num);
			}
			while (!positions.empty()) {
				scanf("%i%*c", &num);
				matrix[i][positions.front() - 1] = num;
				positions.pop();
			}
		}
		printf("%i %i\n", n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[j][i] != 0) {
					positions.push(j + 1);
				}
			}
			printf("%i", positions.size());
			if (positions.size() == 0) {
				printf("\n\n");
				continue;
			}
			queue <int> positionsj;
			while(!positions.empty()) {
				printf(" %i", positions.front());
				positionsj.push(positions.front());
				positions.pop();
			}
			printf("\n");
			if (!positionsj.empty()) {
				printf("%i", matrix[positionsj.front() - 1][i]);
				positionsj.pop();
			}
			while(!positionsj.empty()) {
				printf(" %i", matrix[positionsj.front() - 1][i]);
				positionsj.pop();
			}
			printf("\n");
		}
	}
	return 0;
}