// Usage of list

#include <stdio.h>
#include <stdlib.h>
#include "../libs/llist.h"

typedef struct{
	int a;
	double b;
} st;

int main(){
	
	st s1 = {.a = 1, .b = 2.0};
	double c = 3.0;
	node *n1 = Node(&s1, sizeof s1);
	llist l = Llist("lista", NULL);
	
	insert(&l, n1);
	//l.head = n1;
	printf("%d\n%f\n", ((st*)l.head->data)->a, s1.b);

	return 0;
	
}
