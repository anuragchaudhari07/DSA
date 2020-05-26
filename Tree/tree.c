#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h"
#define RIGHT 200
#define LEFT 300

int max(int a, int b) {
	int result;
	result = a > b ? a:b;
	return result;
}

void tinit(tree *t) {
	*t = NULL;
}


void preorder(tree t) {
	if(t == NULL)
		return;
	printf("%s ", t->str);
	preorder(t->left);
	preorder(t->right);
}


void inorder(tree t) {
	if(t == NULL)
		return;	
	inorder(t->left);
	printf("%s ", t->str);
	inorder(t->right);	
}


void postorder(tree t) {
	if(t == NULL)
		return;	
	postorder(t->left);
	postorder(t->right);
	printf("%s ", t->str);	
}


int count(tree t) {
	if(t == NULL)
		return 0;
	return 1 + count(t->left) + count(t->right);
}


int depth(tree t) {
	int x, y;
	if(t == NULL)
		return -1;
	x = depth(t->left);
	y = depth(t->right);
	return 1 + max(x, y);	
}


void insert(tree *t, char *str) {
	node *p,*q,*tmp;
	p = *t;
	int result;

	tmp = (node *) malloc(sizeof(node));
	tmp->str = (char *) malloc(strlen(str) + 1);
	strcpy(tmp->str, str);
	tmp->left = NULL;
	tmp->right = NULL;
	
	while(p != NULL) {
		q = p;
		result = strcmp(p->str, str);

		if(result < 0)
			p = p->right;
		else if(result > 0)
			p = p->left;
		else
			return;
	}

	if(*t == NULL) {
		*t = tmp;
		return;
	}

	if(result < 0) 
		q->right = tmp;

	else
		q->left = tmp;
	
} 

void remov(tree *t, char *str) {
	node *p,*q,*r,*rp;
	int direction, result;

	p = *t;

	while(p!=NULL) {
		result = strcmp(p->str, str);
		
		if(result < 0) {
			q = p;
			p = p->right;
			direction = RIGHT;
		}
		else if(result > 0) {
			q = p;
			p = p->left;
			direction = LEFT;
		}
		else
			break;
	}

	if(p == NULL)
		return;

	/* p is child and q is parent*/

	/* remove leaf node*/

	if(p->left == NULL && p->right == NULL) {
		if(*t == p) {
			free(p->str);
			free(p);
			*t = NULL;
			return;
		}

		if(direction == RIGHT) {
			free(p->str);
			free(p);
			q->right = NULL;
			return;
		}
		else {
			free(p->str);
			free(p);
			q->left = NULL;
			return;
		}
			
	}
	
	/*remove node with one child*/

	if(p->left != NULL && p->right == NULL) {
		if(direction == RIGHT)
			q->right = p->left;	
		else
			q->left = p->left;
	
		free(p->str);
		free(p);
		return;

	}

	if(p->left == NULL && p->right != NULL) {
		if(direction == RIGHT)
			q->right = p->right;	
		else
			q->left = p->right;

		free(p->str);
		free(p);
		return;

	}

	/* romove node with 2 childs with right approach
	* first traverse p->right and then left upto to find minimum element*/

	r = p->right;

	while(r->left != NULL) {
		rp = r;
		r = r->left;
		
	}

	if(r == p->right) {
		p->right = r->right;
		free(p->str);
		p->str = r->str;
		free(r);
		return;
	}

	if(r->right != NULL)
		rp->left = r->right;
	else
		rp->left = NULL;

	free(p->str);
	p->str = r->str;
	free(r);
	
	
}













