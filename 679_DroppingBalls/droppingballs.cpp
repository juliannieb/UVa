/*
Julian Niebieskikwiat Godoy - A01207868
	
	ALGORITMO:

		1. Empezar la respuesta en 1
		2. Revisar si el numero de pelota es par
			2.1 Si es par
				2.1.1. Dividir el numero de la pelota entre 2
				2.1.2. Multiplicar la respuesta por 2 y sumarle 1 ya que la pelota se va a la derecha
			2.2. Si no es par
				2.2.1. Sumarle al numero de la pelota 1 y dividir el resultado entre 2
				2.2.2. Multiplicar la respuesta por dos ya que la pelota se va a la izquierda
		3. Repetir el paso 2 el numero de niveles del arbol

*/

#include <cstdio>

using namespace std;

int main () {
	int t;
	while (scanf("%i%*c", &t) == 1) {
		if (t == -1) break;
		int nivel;
		int pelota;
		while (t--) {
			scanf("%i %i%*c", &nivel, &pelota);
			int res = 1;
			for (int i = 1; i < nivel; i++) {
				if (pelota % 2 == 0) {
					pelota /= 2;
					res = (res * 2) + 1;
				}
				else {
					pelota = (pelota + 1) / 2;
					res *= 2;
				}
			}
			printf("%i\n", res);
		}
	}
	return 0;
}