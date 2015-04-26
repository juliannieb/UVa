#include <cstdio>
#include <algorithm>

using namespace std;

int matrix[110][110];

int main () {
	int N;
	while (scanf("%i%*c", &N) == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%i%*c", &matrix[i][j]);
				if (i > 0) matrix[i][j] += matrix[i - 1][j];
				if (j > 0) matrix[i][j] += matrix[i][j - 1];
				if (i > 0 && j > 0) matrix[i][j] -= matrix[i - 1][j - 1];
			}
		}
		int maxSubRect = -127 * 100 * 100;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
			for (int k = i; k < N; k++) for (int m = j; m < N; m++) {
				int subRect = matrix[k][m];
				if (i > 0) subRect -= matrix[i - 1][m];
				if (j > 0) subRect -= matrix[k][j - 1];
				if (i > 0 && j > 0) subRect += matrix[i - 1][j - 1];
				maxSubRect = max(maxSubRect, subRect);
			}
		printf("%i\n", maxSubRect);
	}
	return 0;
}