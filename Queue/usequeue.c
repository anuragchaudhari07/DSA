#include<stdlib.h>
#include<stdio.h>
#include "queue.h"


int main() {
	int i,temp;
	queue q;

	init(&q);

	for(i=0;i<10;i++) {
		enqueue(&q, i);
	}

	while(!isempty(&q)) {
		temp = dequeue(&q);
		printf("%d\n", temp);	

	}
	
	return 0;

}
