typedef struct node {
	char *str;
	struct node *left, *right;
}node;

typedef node *tree;

int max(int a, int b);
void tinit(tree *t);
void preorder(tree t);
void inorder(tree t);
void postorder(tree t);
int count(tree t);
int depth(tree t);
void insert(tree *t, char *str);
void remov(tree *t, char *str);


