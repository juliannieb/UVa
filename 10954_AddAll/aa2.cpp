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
		vector <int> numeros(N);
		
		//int num;
		for (int i = 0; i < N; i++) {
			scanf("%i%*c", &numeros[i]);
			//numeros.push(num);
		}
		//sort (numeros.begin(), numeros.end(), my_function);
		priority_queue <int> pq (numeros, numeros + N);
		int total = 0;
		for (int i = 0; i < N; i++) {
			//total += total + numeros.top();
			printf("%i\n", pq.top());
			pq.pop();
		}
		//printf("%i\n", numeros.top());
	}
	return 0;
}