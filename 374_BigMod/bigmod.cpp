#include <cstdio>
#include <math.h>

using namespace std;

int main () {
	int b, p, m;
	while (scanf("%i%*c%i%*c%i%*c", &b, &p, &m) == 3) {
		printf("%i %i %i\n", b, p, m);
		int result = ((int)pow(b, p)) % m;
		printf("%i\n", result);
		getchar();
	}
	return 0;
}