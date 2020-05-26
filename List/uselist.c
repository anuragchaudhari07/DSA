#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "list.h"

int main() {
	list l;
	int ch,pos;
	char str[128];

	init(&l);
	
	

	
	
	while(1){
		traverse(l);

		printf("Enter Your Choice: \n");
		printf("1: Insert: \n");
		printf("2: Print: \n");
		printf("3: Length: \n");
		printf("4: Remove: \n");
		scanf("%d",&ch);

		switch(ch) {
			case 1:
				printf("Enter string and position to insert: \n");
				scanf("%s%d", str, &pos);
				insert(&l, str, pos);
				break;

			case 2:
				traverse(l);
				break;

			case 3:
				printf("Length of List: %d \n", length(l));
				break;

			case 4:
				printf("Enter position to remove: \n");
				scanf("%d",&pos);
				destroy(&l, pos);
				break;
			
			default:
				break;

		}

	}

	return 0;

}


