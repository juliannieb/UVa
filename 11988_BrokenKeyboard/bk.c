#include <stdio.h>
#include <stdlib.h>

struct node {
	char c;
	struct node *next;
};

struct list {
	struct node *head;
	struct node *tail;
	int size;
};

struct node * crea_nodo (char c) {
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n -> c = c;
	n -> next = NULL;
	return n;
}

struct list * crea_lista () {
	struct list *l = (struct list*)malloc(sizeof(struct list));
	l -> head = NULL;
	l -> tail = NULL;
	l -> size = 0;
	return l;
}

int is_empty (struct list *l) {
	return (l -> size == 0);
}

void enqueue (struct list *l, struct node *n) {
	if (!is_empty(l)) {
		l -> tail -> next = n;
		l -> tail = n;
	}else {
		l -> head = n;
		l -> tail = n;
	}
	(l -> size)++;
}

char dequeue (struct list *l) {
	if (!is_empty(l)) {
		struct node *n = l -> head;
		if (l -> size == 1) {
			l -> head = NULL;
			l -> tail = NULL;
		}else {
			l -> head = n -> next;
		}
		(l -> size)--;
		char c = n -> c;
		free(n);
		return c;
	}else {
		return ;
	}
}

void encadena_principio (struct list *principal, struct list *secundaria) {
	if (!is_empty(principal)) {
		if (!is_empty(secundaria)) {
			secundaria -> tail -> next = principal -> head;
			principal -> head = secundaria -> head;
		}
	}else {
		if (!is_empty(secundaria)) {
			principal -> head = secundaria -> head;
			principal -> tail = secundaria -> tail;
		}
	}
	(principal -> size) += (secundaria -> size);
}

void encadena_final (struct list *principal, struct list *secundaria) {
	if (!is_empty(principal)) {
		if (!is_empty(secundaria)) {
			principal -> tail -> next = secundaria -> head;
			principal -> tail = secundaria -> tail;
		}
	}else {
		if (!is_empty(secundaria)) {
			principal -> tail = secundaria -> tail;
			principal -> head = secundaria -> head;
		}
	}
	(principal -> size) += (secundaria -> size);
}

int main () {
	char linea[100000];
	while (scanf("%s\n", &linea) != EOF) {
		struct list *principal = crea_lista();
		struct list *secundaria = crea_lista();
		int i = 0;
		int home = 0;
		int end = 1;
		while (linea[i] != '\0') {
			if (linea[i] == '[') {
				if (home) {
					encadena_principio(principal, secundaria);
				}else if (end) {
					encadena_final(principal, secundaria);
				}
				secundaria = crea_lista();
				home = 1;
				end = 0;
			}else if (linea[i] == ']') {
				if (home) {
					encadena_principio(principal, secundaria);
				}else if (end) {
					encadena_final(principal, secundaria);
				}
				secundaria = crea_lista();
				home = 0;
				end = 1;
			}else {
				enqueue(secundaria, crea_nodo(linea[i]));
			}
			i++;
		}

		if (home) {
			encadena_principio(principal, secundaria);
		}else if (end) {
			encadena_final(principal, secundaria);
		}
		while (!is_empty(principal)) {
			printf("%c", dequeue(principal));
		}
		puts("");
	}
	return 0;
}