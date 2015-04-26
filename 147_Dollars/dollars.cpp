#include <cstdio>

using namespace std;

long long dp [15][30010];

int main () {
	int types [] = {0, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

	for (int i = 12; i > 0; i--) {
		for (int j = 0; j <= 30010; j++) {
			if (i > 11) dp[i][j] = 0;
			else if (j < 0) dp[i][j] = 0;
			else if (j == 0) dp[i][j] = 1;
			else if (j > 0) {
				if ((j - types[i]) < 0) dp[i][j] = dp[i + 1][j];
				else dp[i][j] = dp[i + 1][j] + dp[i][j - types[i]];
			}
		}
	}

	long n1, n2;
	while (scanf("%ld.%ld%*c", &n1, &n2) == 2) {
		if (n1 == 0 && n2 == 0) break;
		long num = (n1 * 100) + n2;
		printf("%3ld.%.2ld%17lld\n", n1, n2, dp[1][num]);
	}
	return 0;
}