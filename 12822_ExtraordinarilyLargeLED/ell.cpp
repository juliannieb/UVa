#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int valor (int n) {
	int valor = 0;
	switch (n) {
		case 0:
		case 6:
		case 9:
			valor = 6;
			break;
		case 1:
			valor = 2;
			break;
		case 2:
		case 3:
		case 5:
			valor = 5;
			break;
		case 4:
			valor = 4;
			break;
		case 7:
			valor = 3;
			break;
		case 8:
			valor = 7;
			break;
	}
	return valor;
}

int gasto (int n) {
	if (n == 0) return valor(n);
	else {
		int total = 0;
		while (n > 0) {
			total += valor (n % 10);
			n = n / 10;
		}
		return total;
	}
}

int main () {
	char info[6];
	int h, m, s;
	int i = 1;
	while (scanf("%s %d:%d:%d%*c", &info, &h, &m, &s) != EOF) {
		int home = 0;
		int guest = 0;
		int hora_inic = (h * 3600) + (m * 60) + s;
		int hora_fin = 0;
		char team[10];
		int points;
		int total = 0;
		while (1) {
			scanf("%s", &info);
			if (strcmp(info, "END") == 0) {
				scanf("%d:%d:%d%*c", &h, &m, &s);
				hora_fin = (h * 3600) + (m * 60) + s;
				total += gasto(home) * (hora_fin - hora_inic);
				total += gasto(guest) * (hora_fin - hora_inic);
				hora_inic = hora_fin;
				break;
			}else {
				scanf("%d:%d:%d %s %d%*c", &h, &m, &s, &team, &points);
				hora_fin = (h * 3600) + (m * 60) + s;
				total += gasto(home) * (hora_fin - hora_inic);
				total += gasto(guest) * (hora_fin - hora_inic);
				hora_inic = hora_fin;
				if (strcmp(team, "home") == 0) home += points;
				else guest += points;
			}
			
		}
		printf("Case %i: %i\n", i, total);
		i++;
	}
	return 0;
}