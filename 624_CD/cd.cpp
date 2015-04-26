#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main () {
	int N, M;
	while (scanf("%i%*c%i%*c", &N, &M) == 2) {
		if (N == 0 && M == 0) break;
		map <int, int> jack;
		while (N--) {
			int num;
			scanf("%i%*c", &num);
			jack[num] = 1;
		}
		int cont = 0;
		while (M--) {
			int num;
			scanf("%i%*c", &num);
			if (jack[num] == 1) cont++;
		}
		printf("%i\n", cont);
	}
	return 0;
}