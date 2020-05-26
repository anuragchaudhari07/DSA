#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "list.h"


void init(list *l) {
	l->p = NULL;
	l->q = NULL;
}


void insert(list *l, char *str, int pos) {
	int len;
	int i;
	node *temp,*x;
	
	len = length(*l);

	if(pos < 0 || pos > len)
		return;

	x = (node *) malloc(sizeof(node));
	x->str = (char *) malloc(sizeof(strlen(str)) + 1);
	strcpy(x->str, str);

	if(len == 0) {
		l->p = x;
		l->q = x;
		x->next = x;
		x->prev = x;
		return;		
	}

	temp = l->p;

	if(pos == 0)
		temp = l->q; 
	
	
	for(i=0;i<pos-1;i++) {
		temp = temp->next;	
	}

	
	temp->next->prev = x;
	x->next = temp->next;
	temp->next = x;
	x->prev = temp;

	if(pos == 0)
		l->p = x;
	if(pos == len)
		l->q = x;
		
}


void traverse(list l) {
	node *temp;
	temp = l.p;
	
	printf("List: [ ");

	if(temp == NULL) {
		printf(" ]\n");
		return;
	}
		

	do {
		printf("%s ", temp->str);
		temp = temp->next;	
	}while(temp!=l.p);

	printf(" ]\n");

	temp = l.q;
	
	printf("Rev: [ ");

	do {
		printf("%s ", temp->str);
		temp = temp->prev;	
	}while(temp!=l.q);

	printf(" ]\n");
}

int length(list l) {
	node *temp;
	int len = 0;
	temp = l.p;
	
	if(temp == NULL) {
		return 0;
	}

	do {
		temp = temp->next;
		len++;	
	}while(temp!=l.p);

	return len;
	
}


void destroy(list *l, int pos) {
	node *temp, *tmp;
	int len,i;
	
	len = length(*l);	
	
	if(len == 0)
		return;

	if(pos < 0 || pos > len - 1)
		return;
	
	temp= l->p;

	if(len == 1) {
		l->p = NULL;
		l->q = NULL;
		free(temp->str);
		free(temp);
		return;
	}

	for(i=0;i<pos-1;i++) {
		temp = temp->next;
	}

	if(pos == 0) 
		temp=l->q;

	tmp = temp->next;

	/*if(pos == 0) {
		tmp->next->prev = temp;
		temp->next =tmp->next;
		l->p = tmp->next;
		free(tmp->str);
		free(tmp);
		return;

	}

	if(pos == len - 1) {
		tmp->next->prev = temp;
		temp->next =tmp->next;
		l->q = tmp->prev;
		free(tmp->str);
		free(tmp);
		return;
	}*/

	tmp->next->prev = temp;
	temp->next =tmp->next;
	free(tmp->str);
	free(tmp);

	if(pos == 0)
		l->p = temp->next;
	if(pos == len - 1)
		l->q = temp;	
	
}














