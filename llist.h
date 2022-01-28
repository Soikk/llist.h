#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
	void *data;
	struct node *next;
} node;

typedef struct llist{
	char *name;
	node *head;
} llist;

node *Node(void *data, size_t size){
	node *nnode = malloc(sizeof(node));
	nnode->data = malloc(size);
	memmove(nnode->data, data, size);
	nnode->next = NULL;
	return nnode;
}

llist Llist(char *name, node *head){
	llist nllist = {.name = name, .head = head};
	return nllist;
}

void append(llist l, node *n){
	if(l.head != NULL){
		node *temp = l.head;
		while(temp->next != NULL)
			temp = temp-> next;
		temp->next = n;
	}else{
		l.head = n;
	}
}

void insert(llist *l, node *n){
	if(l->head != NULL){
		node *temp = l->head;
		n->next = temp;
	}
	l->head = n;
}

void insertPos(llist *l, node *n, size_t pos){
	int i = 0;
	if(l->head != NULL){
		if(pos == 0){
			insert(l, n);
			return;
		}
		node *t = NULL;
		node *tnext = l->head;
		for(i = 0; i < pos && tnext != NULL; ++i){
			t = tnext;
			tnext = t->next;
		}
		if(tnext == NULL && i != pos){
			goto poserr;
		}
		t->next = n;
		n->next = tnext;
	}
poserr:
	fprintf(stderr, "Couldn't insert at desired position. "
			"Inserting at position %d", i);
}
