#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main () {
	int n;
	scanf("%i%*c", &n);
	int b[30];
	int a[30];
	int num;
	char c;
	for (int i = 0; i < n; i++) {
		scanf("%i%*c", &num);
		b[num - 1] = i + 1;
	}
	int i = 0;
	while (scanf("%i%*c", &num) == 1) {
		a[num - 1] = i + 1;
		i++;

 		if (i == n) {
			int matriz [30][30];
			memset(matriz, 0, sizeof(matriz));
			for (int j = 1; j < n + 1; j++) {
				for (int k = 1; k < n + 1; k++) {
					if (a[j - 1] == b[k - 1]) matriz[j][k] = matriz[j - 1][k - 1] + 1;
					else matriz[j][k] = max(matriz[j - 1][k], matriz[j][k - 1]);
				}
			}
			printf("%i\n", matriz[n][n]);
			i = 0;
		}
	}
	return 0;
}