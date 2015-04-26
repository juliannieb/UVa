#include <cstdio>

using namespace std;

int main () {
	int k;
	int test_case = 0;
	while(scanf("%i%*c", &k) == 1) {
		if (k == 0) break;
		int lotto[15];
		if (test_case) printf("\n");
		for (int i = 0; i < k; i++) {
			scanf("%i%*c", &lotto[i]);
		}
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				for (int m = j + 1; m < k; m++) {
					for (int n = m + 1; n < k; n++) {
						for (int o = n + 1; o < k; o++) {
							for (int p = o + 1; p < k; p++) {
								printf("%i %i %i %i %i %i\n", lotto[i], lotto[j], lotto[m], lotto[n], lotto[o], lotto[p]);	
							}
						}
					}
				}
			}
		}
		test_case++;
	}
	return 0;
}