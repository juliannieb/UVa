//Julian Niebieskikwiat Godoy - A01207868

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char bitmap [205][205];
char bitmap_d [1000000];
int indice;

void b_a_d (int xi, int xs, int yi, int ys) {
	if (xs >= xi && ys >= yi) {
		
		char aux = bitmap[yi][xi];
		bool todos_iguales = true;
		for (int i = yi; i <= ys; i++) {
			for (int j = xi; j <= xs; j++) {
				if (bitmap[i][j] != aux) {
					todos_iguales = false;
					break;
				}
			}
			if (!todos_iguales) break;
		}
		if (todos_iguales) {
			printf("%c", aux);
			indice++;
			if (indice % 50 == 0) {
				printf("\n");
				indice = 0;
			}
		}
		else {
			printf("D");
			indice++;
			if (indice % 50 == 0) {
				printf("\n");
				indice = 0;
			}
			int mitad_x = (xi + xs) / 2;
			int mitad_y = (yi + ys) / 2;
			b_a_d(xi, mitad_x, yi, mitad_y);
			b_a_d(mitad_x + 1, xs, yi, mitad_y);
			b_a_d(xi, mitad_x, mitad_y + 1, ys);
			b_a_d(mitad_x + 1, xs, mitad_y + 1, ys);
		}
	}
}

void d_a_b (int ri, int ci, int rf, int cf) {
	if (rf >= ri && cf >= ci) {
		if (bitmap_d[indice] == '1') {
			indice++;
			for (int i = ri; i <= rf; i++) {
				for (int j = ci; j <= cf; j++) {
					bitmap[i][j] = '1';
				}
			}
			return;
		}
		else if (bitmap_d[indice] == '0') {
			indice++;
			for (int i = ri; i <= rf; i++) {
				for (int j = ci; j <= cf; j++) {
					bitmap[i][j] = '0';
				}
			}
			return;
		}
		else {
			indice++;
			int mitad_r = (ri + rf) / 2;
			int mitad_c = (ci + cf) / 2;
			d_a_b(ri, ci, mitad_r, mitad_c);
			d_a_b(ri, mitad_c + 1, mitad_r, cf);
			d_a_b(mitad_r + 1, ci, rf, mitad_c);
			d_a_b(mitad_r + 1, mitad_c + 1, rf, cf);
		}
	}
}

int main () {
	char c;
	while (scanf("%c%*c", &c) == 1) {
		if (c == '#') break;
		int rows, columns;
		scanf("%i %i%*c", &rows, &columns);
		
		if (c == 'B') {
			char val;

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					scanf("%c", &val);
					if (val != '\n') {
						bitmap[i][j] = val;
					}
					else j--;
				}
			}
			printf("D%4i%4i\n", rows, columns);
			indice = 0;
			b_a_d(0, columns - 1, 0, rows - 1);
			if (indice != 0 || (rows == 0 && columns == 0)) printf("\n");
			getchar();
		}

		else if (c == 'D') {
			char value;
			gets(bitmap_d);
			indice = 0;
			printf("B%4i%4i\n", rows, columns);
			d_a_b(0, 0, rows - 1, columns - 1);
			int cont = 0;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					printf("%c", bitmap[i][j]);
					cont++;
					if (cont % 50 == 0) {
						printf("\n");
						cont = 0;
					}
					
				}
			}
			if (cont != 0 || (rows == 0 && columns == 0)) printf("\n");
		}
		
	}
	return 0;
}