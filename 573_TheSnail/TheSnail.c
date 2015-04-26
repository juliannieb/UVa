#include <stdio.h>
#include <stdlib.h>

int * snail_well (float h, float u, float d, float f) {
	int * snail;
	snail = malloc(2 * sizeof(int));
	int days = 1;
	int success = 0;
	float height = 0;
	while(height >= 0) {
		height += u;
		if (height > h) {
			success = 1;
			break;
		}
		height -= d;
		if (height < 0) {
			break;
		}
		u -= f;
		if (u < 0) u = 0;
		days += 1;
	}
	snail[0] = success;
	snail[1] = days;
	return snail;
}

int main () {
	float h, u, d, f;
	while (scanf("%f%*c%f%*c%f%*c%f%*c", &h, &u, &d, &f) != EOF) {
		if (h == 0.0) break;
		f /= 100.0;
		f = u * f;
		int * caracol = snail_well(h, u, d, f);
		if (caracol[0]) {
			printf("success on day %i\n", caracol[1]);
		}else {
			printf("failure on day %i\n", caracol[1]);
		}
	}
	return 0;
}