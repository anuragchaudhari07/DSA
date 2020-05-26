#define SIZE 64

typedef struct stack {
	int i;
	int a[SIZE];
}stack;

void init(stack *s);
void push(stack *s, int num);
int pop(stack *s);
int isempty(stack *s);
int isfull(stack *s);


