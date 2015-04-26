#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool my_function (int i, int j) { return (j < i); }

int main () {
	int N, G;
	while (scanf("%i %i%*c", &N, &G) == 2) {
		int S, R;
		int points = 0;
		vector <int> differences;
		while (N--) {
			scanf("%i %i%*c", &S, &R);
			int dif = S - R;
			if (dif > 0) points += 3;
			else {
				differences.push_back(dif);
			}
		}
		sort(differences.begin(), differences.end(), my_function);
		for (int i = 0; i < differences.size(); i++) {
			while (G && differences[i] <= 0) {
				differences[i]++;
				G--;
			}
			if (differences[i] == 0) points++;
			else if (differences[i] > 0) points += 3;
			if (!G && differences[i] < 0) break;
		}
		printf("%i\n", points);
	}
	return 0;
}