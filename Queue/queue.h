#define SIZE 32

typedef struct queue {
	int r,f,count;
	int a[SIZE];
}queue;


void init(queue *q);
void enqueue(queue *q, int no);
int dequeue(queue *q);
int isempty(queue *q);
int isfull(queue *q);
