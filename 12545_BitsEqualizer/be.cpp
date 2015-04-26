#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main () {
	int c;
	scanf("%i%*c", &c);
	for (int k = 1; k <= c; k++) {
		//if (k > 1) printf("\n");
		char s[200];
		char t[200];
		gets(s);
		gets(t);
		int movimientos = 0;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] != t[i] && (s[i] == '0' || s[i] == '1')) {
				for (int j = i + 1; j < strlen(s); j++) {
					if (s[j] != t[j] && s[j] != s[i] && (s[j] == '0' || s[j] == '1')) {
						char aux = s[i];
						s[i] = s[j];
						s[j] = aux;
						movimientos++;
						break;
					}
				}
			}
		}
		if (strcmp(s, t) == 0) {
			printf("Case %i: %i\n", k, movimientos);
			continue;
		}
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] != t[i]) {
				if (s[i] == '?') {
					if (t[i] == '0') {
						s[i] = '0';
						movimientos++; 
					}else {
						for (int j = 0; j < strlen(s); j++) {
							if (s[j] != t[j] && s[j] == '1') {
								s[i] = '1';
								s[j] = '?';
								movimientos++;
								break;
							}
						}
					}
				}else if (s[i] == '0'){
					s[i] = '1';
					movimientos++;
				}else {
					for (int j = 0; j < strlen(s); j++) {
						if (s[j] != t[j] && s[j] == '?' && t[j] == '1') {
							s[i] = '?';
							s[j] = '1';
							movimientos++;
							break;
						}
					}
				}
			}
		}
		if (strcmp(s, t) == 0) {
			printf("Case %i: %i\n", k, movimientos);
			continue;
		}
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] != t[i] && s[i] != '1') {
				s[i] = t[i];
				movimientos++;
			}
		}
		if (strcmp(s, t) == 0) printf("Case %i: %i\n", k, movimientos);
		else printf("Case %i: -1\n", k);
	}
	return 0;
}