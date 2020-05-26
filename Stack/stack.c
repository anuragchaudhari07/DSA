#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void init(stack *s) {
	s->i = 0;
}

void push(stack *s, int num) {
	s->a[s->i] = num;
	s->i++;
}

int pop(stack *s) {
	int temp;
	temp = s->a[s->i-1];
	s->i--;
	return temp;
}

int isempty(stack *s) {
	return s->i == 0;
}

int isfull(stack *s) {
	return s->i == SIZE;
}
		
