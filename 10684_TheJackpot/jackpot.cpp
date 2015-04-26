#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
	int n;
	while (scanf("%i%*c", &n) == 1) {
		if (n == 0) break;
		int sum = 0;
		int ans = 0;
		int num;
		for (int i = 0; i < n; i++) {
			scanf("%i%*c", &num);
			sum += num;
			ans = max(ans, sum);
			if (sum < 0) sum = 0;
		}
		if (!ans) printf("Losing streak.\n");
		else printf("The maximum winning streak is %i.\n", ans);
	}
	return 0;
}