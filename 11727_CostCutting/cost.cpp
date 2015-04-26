#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

int main () {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		vector < int > empleados (3);
		scanf("%i %i %i%*c", &empleados[0], &empleados[1], &empleados[2]);
		sort(empleados.begin(), empleados.end(), myfunction);
		printf("Case %i: %i\n", i, empleados[1]);
	}
	return 0;
}