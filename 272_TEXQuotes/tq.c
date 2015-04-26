#include <stdio.h>
#include <stdlib.h>

int main () {
	char c;
	int i = 0;
	while (scanf("%c", &c) == 1) {
		if (c == 34) {
			if (i % 2 == 0) printf("``");
			else printf("''");
			i++;
		}else printf("%c", c);
	}
	return 0;
}