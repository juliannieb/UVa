#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

int main () {
	int n;
	while (scanf("%i%*c", &n) == 1) {
		if (n == 0) break;
		vector <int> ages(n);
		int num;
		for (int i = 0; i < n; i++) {
			scanf("%i%*c", &ages[i]);
		}
		sort (ages.begin(), ages.end(), myfunction);
		printf("%i", ages[0]);
		for (int i = 1; i < n; i++) {
			printf(" %i", ages[i]);
		}
		printf("\n");
	}
	return 0;
}