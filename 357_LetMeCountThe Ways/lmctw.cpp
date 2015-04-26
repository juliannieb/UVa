#include <cstdio>

using namespace std;

long long dp [15][30010];

int main () {
	int types [] = {0, 1, 5, 10, 25, 50};

	for (int i = 6; i > 0; i--) {
		for (int j = 0; j <= 30010; j++) {
			if (i > 5) dp[i][j] = 0;
			else if (j < 0) dp[i][j] = 0;
			else if (j == 0) dp[i][j] = 1;
			else if (j > 0) {
				if ((j - types[i]) < 0) dp[i][j] = dp[i + 1][j];
				else dp[i][j] = dp[i + 1][j] + dp[i][j - types[i]];
			}
		}
	}

	int n;
	while (scanf("%i%*c", &n) == 1) {
		if (dp[1][n] == 1) printf("There is only 1 way to produce %i cents change.\n", n);
		else printf("There are %lld ways to produce %i cents change.\n", dp[1][n], n);
	}
	return 0;
}