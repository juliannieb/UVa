#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare (int i, int j) { return (i < j); }

long long int convierte_int (vector <int> courses) {
	long long int res = 0;
	for (int i = 0; i < 5; i++) {
		res = (res * 1000) + courses[i];
	}
	return res;
}

int main () {
	int n;
	while (scanf("%i%*c", &n) == 1) {
		if (n == 0) break;
		vector < vector <int> > courses (n, vector <int> (5));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				scanf("%i%*c", &courses[i][j]);
			}
		}
		map <long long int, int> courses_together;
		int cont = 0;
		int mayor = 0;
		for (int i = 0; i < n; i++) {
			sort(courses[i].begin(), courses[i].end(), compare);
			long long int ci = convierte_int(courses[i]);
			courses_together[ci] += 1;
			int temp = courses_together[ci];
			if (temp > mayor) {
				mayor = temp;
				cont = temp;
			}else if (temp == mayor){
				cont += temp;
			}
		}
		printf("%i\n", cont);
	}
	return 0;
}