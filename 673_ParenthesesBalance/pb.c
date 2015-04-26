#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
	char value;
	struct node* next;
};

struct list {
	struct node* head;
	int size;
};

int is_empty(struct list *lst) {
    return (lst->head == 0);
}

void add_first(struct list *lst, char val) {
    struct node *n;
    n = (struct node*) malloc( sizeof(struct node) );
	assert(n != 0);
    n->value = val;
    n->next = lst->head;   
    lst->head = n;
    lst->size++;
}

char remove_first(struct list *lst) {
    struct node *p;
    char val;
    
    assert( !is_empty(lst) );
    p = lst->head;    
    lst->head = p->next;
    p->next = 0;
    val = p->value;
    free(p);
    lst->size--;
    return val;
}

char get_first(struct list *lst) {
    struct node *p;  
    assert( !is_empty(lst) );  
    p = lst->head;
    return p->value;
}

int main () {
	int t;

	while (scanf("%i%*c", &t) != EOF) {
		while (t) {

			struct list pila;

			pila.head = NULL;
			pila.size = 0;

			char str[128];
			gets(str);

			int len = strlen(str);
			int i;
			char p;
			int flag = 1;

			for (i = 0; i < len; i ++) {
				p = str[i];

				if (is_empty(&pila) && (p == ')' || p == ']')) {
					flag = 0;
					printf("No\n");
					break;
				}else if (p == '(' || p == '[') {
					add_first(&pila, p);
				}else if (p == ')') {
					if (get_first(&pila) == '(') remove_first(&pila);
					else {
						flag = 0;
						printf("No\n");
						break;
					}
				}else if (p == ']') {
					if (get_first(&pila) == '[') remove_first(&pila);
					else {
						flag = 0;
						printf("No\n");
						break;
					}
				}
			}

			if (flag) {
				if (is_empty(&pila)) {
					printf("Yes\n");
				}else {
					printf("No\n");
				}
			}
			t--;
		}
	}
	return 0;
}