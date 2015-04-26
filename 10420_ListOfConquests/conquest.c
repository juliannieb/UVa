#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
	char str[75];
};
typedef struct string String;

void quick_sort(struct string *arreglo, int first, int last) {
	int center = (first +  last) / 2;
	struct string pivot = arreglo[center];
	int bottom = first;
	int top = last;
	while (bottom <= top) {
		while (strcmp(arreglo[bottom].str, pivot.str) < 0) bottom++;
		while (strcmp(arreglo[top].str, pivot.str) > 0) top--;
		if (bottom <= top) {
			struct string aux;
			strcpy(aux.str, arreglo[top].str);
			strcpy(arreglo[top].str, arreglo[bottom].str);
			strcpy(arreglo[bottom].str, aux.str);
			bottom++;
			top--;
		}
	}
	if (first < top) 
		quick_sort(arreglo, first, top);
	if (bottom < last)
		quick_sort(arreglo, bottom, last);

}


int main () {
	int t;
	scanf("%i%*c", &t);
	String *paises = NULL;
	char trash [75];
	paises = (String*) malloc(sizeof(String) * t);
	int aux = t;
	int i = 0;
	while (t --) {
		scanf("%s", paises[i].str);
		gets(trash);
		i ++;
	}
	quick_sort(paises, 0, aux - 1);

	int j;
	int cont;

	for (i = 0; i < aux; i ++) {

		if (strcmp(paises[i].str, "\0") != 0) {
			cont = 0;
			struct string actual;
			strcpy (actual.str, paises[i].str);
			for (j = i; j < aux; j ++) {
				if (strcmp(paises[j].str, actual.str) == 0) {
					cont ++;
					strcpy(paises[j].str, "\0");
				}
			}
			printf("%s %i\n", actual.str, cont);
		}
		
	}
	free(paises);
	return 0;

}