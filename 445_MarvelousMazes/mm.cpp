#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main () {
	char s[133];
	while (gets(s)) {
		int str_size = strlen(s);
		int total = 0;
		for (int i = 0; i < str_size; i++) {
			if (isdigit(s[i])) total += s[i] - 48;
			else {
				if (s[i] == 'b') {
					while (total--) {
						printf(" ");
					}
				}
				else if (s[i] == '!' || s[i] == '\n') {
					printf("\n");
				}
				else {
					while (total--) {
						printf("%c", s[i]);
					}
				}
				total = 0;
			}
			//printf("total = %i\n", total);
		}
		printf("\n");
	}
	return 0;
}