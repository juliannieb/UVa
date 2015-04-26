#include <cstdio>

using namespace std;

int main () {
	int v, t;
	while (scanf("%i %i%*c", &v, &t) == 2) {
		printf("%i\n", v * (t * 2));
	}
	return 0;
}