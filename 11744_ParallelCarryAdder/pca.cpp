#include <cstdio>
#include <iostream>

using namespace std;

char a[32];
char b[32];

int multiplica_d () {
	int flag = 0;
	for (int i = 30; i >= 0; i--) {
		if (b[i] == '0') {
			if (flag) {
				b[i] = '1';
				flag = 0;
			}else {
				b[i] = '0';
			}
		}else {
			if (flag) {
				b[i] = '1';
			}else {
				b[i] = '0';
			}
			flag = 1;
		}
	}
	if (flag) return 1;
	else return 0;
}

void saca_c_y_d () {
	char c, d;
	for (int i = 0; i < 31; i++) {
		if (a[i] != b[i]) c = '1';
		else c = '0';
		if (a[i] == '1' && b[i] == '1') d = '1';
		else d = '0';
		a[i] = c;
		b[i] = d;
	}
}

int es_cero (char arr[32]) {
	int res = 1;
	for (int i = 0; i < 31; i++) {
		if (arr[i] == '1') {
			res = 0;
			break;
		}
	}
	return res;
}

int main () {
	int t;
	scanf("%i%*c", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%s %s", &a, &b);
		int overflow = 0;
		while (1) {
			printf("%s %s\n", a, b);
			saca_c_y_d ();
			if (multiplica_d()) {
				overflow = 1;
				break;
			}
			if (es_cero(b)) break;
		}
		if (i < t) {
			if (overflow) printf("%s overflow\n\n", a, b);
			else printf("%s %s\n\n", a, b);
		}
		else {
			if (overflow) printf("%s overflow\n", a, b);
			else printf("%s %s\n", a, b);
		}
	}
	return 0;
}