#include <cstdio>

using namespace std;

int main () {
	int n;
	while (scanf("%i%*c", &n) == 1) {
		n % 6 == 0 ? printf("Y\n") : printf("N\n");
	}
	return 0;
}