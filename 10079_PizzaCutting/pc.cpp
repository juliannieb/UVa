#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	long long int N;
	while (scanf("%lli%*c", &N) == 1) {
		if (N < 0) break;
		printf("%lli\n", 1 + (N*(N+1))/2);
	}
	return 0;
}