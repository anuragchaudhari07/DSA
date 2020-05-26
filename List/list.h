typedef struct node {
	char *str;
	struct node *prev, *next;
}node;

typedef struct list {
	node *p, *q;
}list;

void init(list *l);
void insert(list *l, char *str, int pos);
void traverse(list l);
int length(list l);
void destroy(list *l, int pos);
