#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main () {
	int n, b, h, w;
	while (scanf("%i %i %i %i%*c", &n, &b, &h, &w) == 4) {
		int p, a;
		int menor = 99999999;
		string trash;
		while (h--) {
			scanf("%i%*c", &p);
			if (p * n > b || p * n >= menor) {
				getline (cin, trash);
				continue;
			}
			int flag = 0;
			for (int i = 0; i < w; i++) {
				scanf("%i%*c", &a);
				if (a >= n) {
					flag = 1;
					if (i < w - 1) getline (cin, trash);
					break;
				}
			}
			if (flag) {
				menor = p * n;
			}
		}
		if (menor < 99999999) printf("%i\n", menor);
		else printf("stay home\n");
	}
	return 0;
}