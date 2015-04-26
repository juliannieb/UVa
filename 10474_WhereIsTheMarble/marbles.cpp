#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> marbles (10005);

bool myFunction (int i, int j) { return (i < j); }

int main () {
	int n, q;
	int no_case = 1;
	while (scanf("%i %i%*c", &n, &q) == 2) {
		if (n == 0 && q == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%i%*c", &marbles[i]);
		}

		sort(marbles.begin(), marbles.begin() + n, myFunction);

		vector <int> posiciones (10005, -1);
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				if (marbles[i] != marbles[i - 1]) posiciones[marbles[i]] = i + 1;
			}
			else {
				posiciones[marbles[i]] = i + 1;
			}
		}

		int num;
		printf("CASE# %i:\n", no_case);
		while (q--) {
			scanf("%i%*c", &num);
			if (posiciones[num] == -1) printf("%i not found\n", num);
			else printf("%i found at %i\n", num, posiciones[num]);
		}
		no_case++;
	}
	return 0;
}