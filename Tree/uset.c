#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h"


int main() {
	tree t;
	tinit(&t);
	char str[16];

	printf("Count: %d\n", count(t));
	printf("Depth: %d\n", depth(t));
	printf("Preorder: ");
	preorder(t);
	printf("\n");
	printf("Inorder: ");
	inorder(t);
	printf("\n");
	printf("Postorder: ");
	postorder(t);
	printf("\n");

	while(scanf("%s", str) != -1) {
		insert(&t, str);
		printf("Count: %d\n", count(t));
		printf("Depth: %d\n", depth(t));
		printf("Preorder: ");
		preorder(t);
		printf("\n");
		printf("Inorder: ");
		inorder(t);
		printf("\n");
		printf("Postorder: ");
		postorder(t);
		printf("\n");
		getchar();
	}

	while(scanf("%s", str) != -1) {
		remov(&t, str);
		printf("Count: %d\n", count(t));
		printf("Depth: %d\n", depth(t));
		printf("Preorder: ");
		preorder(t);
		printf("\n");
		printf("Inorder: ");
		inorder(t);
		printf("\n");
		printf("Postorder: ");
		postorder(t);
		printf("\n");
		getchar();
	}
}
