#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
	int t;
	scanf("%i%*c", &t);
	while (t--) {
		char c;
		int suma_temp;
		suma_temp = 0;
		int suma_total;
		suma_total = 0;
		int actual;
		actual = 1;
		while (scanf("%c", &c) == 1 && c != '\n') {
			if (c == 'O') {
				suma_temp += actual;
				actual++;
			}else {
				suma_total += suma_temp;
				suma_temp = 0;
				actual = 1;
			}
		}
		suma_total += suma_temp;
		suma_temp = 0;
		actual = 1;
		printf("%i\n", suma_total);
	}
	return 0;
}