#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	int n, k;
	while (scanf("%i%*c%i%*c", &n, &k) == 2) {
		int cigarros = n;
		int colillas = n;
		while(colillas >= k) {
			n = colillas / k;
			cigarros += n;
			colillas = (colillas % k) + n;
		}
		printf("%i\n", cigarros);
	}
	return 0;
}