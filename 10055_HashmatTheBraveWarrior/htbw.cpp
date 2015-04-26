#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
	long long a, b;
	while (scanf("%lld %lld%*c", &a, &b) == 2) {
		printf("%lld\n", abs(a - b));
	}
	return 0;
}