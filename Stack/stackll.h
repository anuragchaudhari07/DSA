typedef struct node {
	int val;
	struct node *next;
}node;

typedef node *stack;

void init(stack *s);
void push(stack *s, int num);
int pop(stack *s);
int isempty(stack *s);
int isfull(stack *s);

