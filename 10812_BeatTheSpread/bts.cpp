#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	int n;
	scanf("%i%*c", &n);
	while (n--) {
		int s, d;
		scanf("%i %i%*c", &s, &d);
		int flag = 0;
		int i = 0;
		for (i = 0; i <= s; i++) {
			if (i + (i + d) == s) {
				flag = 1;
				break;
			}
		}
		if (flag) printf("%i %i\n", i + d, i);
		else printf("impossible\n");
	}
	return 0;
}