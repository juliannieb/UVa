#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	float h, m;
	while (scanf("%f:%f", &h, &m) == 2) {
		if (h == 0 && m == 0) break;
		float angulo1 = fabs(((h * 30) + (m * 0.5)) - ((m / 5.0) * 30));
		if (angulo1 <= 180) printf("%.3f\n", angulo1);
		else printf("%.3f\n", 360.0 - angulo1);
	}
	return 0;
}