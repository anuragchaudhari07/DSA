#include<stdlib.h>
#include<stdio.h>
#include "stackll.h"

int main() {
	int i,temp;
	stack s;
	init(&s);
	for(i=0;i<10;i++) {
		push(&s,i);
	}
	while(!isempty(&s)) {
		temp = pop(&s);
		printf("%d\n",temp);
	}

	
	return 0;
}



