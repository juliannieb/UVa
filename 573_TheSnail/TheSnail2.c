#include <stdio.h>
#include <stdlib.h>

void snail_well (float h, float u, float d, float f) {
	int days = 0;
	int success = 0;
	float height = 0;
	while(height >= 0) {
		days ++;
		height += u;
		if (height > h) {
			printf("success on day %i\n", days);
			break;
		}
		height -= d;
		if (height < 0) {
			printf("failure on day %i\n", days);
			break;
		}
		u -= f;
		if (u < 0) u = 0;
	}
}

int main () {
	float h, u, d, f;
	while (scanf("%f%*c%f%*c%f%*c%f%*c", &h, &u, &d, &f) != EOF) {
		if (h == 0.0) break;
		f /= 100.0;
		f = u * f;
		snail_well(h, u, d, f);
	}
	return 0;
}