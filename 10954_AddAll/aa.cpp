#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool my_function (int i, int j) { return (i < j); }

int main () {
	int N;
	while (scanf("%i%*c", &N) == 1) {
		if (N == 0) break;
		priority_queue< int, vector<int>, greater<int> > numeros;
		int num;
		for (int i = 0; i < N; i++) {
			scanf("%i%*c", &num);
			numeros.push(num);
		}
		int total = 0;
		while (numeros.size() > 1) {
			num = numeros.top();
			numeros.pop();
			num += numeros.top();
			numeros.pop();
			total += num;
			numeros.push(num);
		}
		printf("%i\n", total);
	}
	return 0;
}