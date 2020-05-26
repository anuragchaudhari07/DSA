#include<stdio.h>
#include<stdlib.h>
#include "stackll.h"



void init(stack *s) {
	*s = NULL;		
}

void push(stack *s, int num) {
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->val = num;
	temp->next = *s;
	*s = temp;
	
}

int pop(stack *s) {
	int temp;
	node *tmp;
	tmp = *s;
	temp = (*s)->val;
	*s = (*s)->next;
	free(tmp);
	return temp;
}

int isempty(stack *s) {
	return *s == NULL;
}

int isfull(stack *s) {
	return 0;
}
		
