#include<stdlib.h>
#include<stdio.h>
#include "queue.h"

void init(queue *q) {
	q->f = 0;
	q->r = q->f - 1;
	q->count = 0;
}

void enqueue(queue *q, int no) {
	q->r = (q->r + 1) % SIZE;
	q->a[q->r] = no;
	q->count++;
}

int dequeue(queue *q) {
	int temp;
	temp = q->a[q->f];
	q->f = (q->f + 1) % SIZE;
	q->count--;
	return temp;
}

int isempty(queue *q) {
	return q->count==0;
}

int isfull(queue *q) {
	return q->count==1;
}


