#include <iostream>
#include <stdio.h>
#include <math.h>

int main () {
	int t;
	scanf("%i%*c", &t);
	int l, d, h, v;
	while (t--) {
		scanf("%i %i %i %i%*c", &l, &d, &h, &v);
		int floor_left_inic = 0;
		int floor_left_fin = d - 500;
		int pool_inic = floor_left_fin + 1000;
		int pool_fin = pool_inic + l - 1000;
		int floor_right_inic = pool_fin + 1000;
		float r = v * (sqrt((2 * h) / 9810.0));
		if (r >= floor_left_inic && r < floor_left_fin) printf("FLOOR\n");
		else if (r > pool_inic && r < pool_fin) printf("POOL\n");
		else if (r > floor_right_inic) printf("FLOOR\n");
		else printf("EDGE\n");
	}
	return 0;
}