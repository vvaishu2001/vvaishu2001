#include<stdio.h>
#include<stdlib.h>
struct node {
	int coeff, exp;
	struct node *next;
} *eqn1 = NULL, *eqn2 = NULL, *eqn3 = NULL;
void dispPoly(struct node *start) {
	
	if(!start) {
		printf("0\n\n");
		return;
	}
	struct node *temp = start;
	int i;
	for(i = 1; temp; i++) {
		printf("%dx%d+ ",temp->coeff,temp->exp);
		temp = temp->next; 
		}
		}                                              
struct node *insNode(struct node *start, int a, int b) {
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->coeff = a;
	head->exp = b;
	if(start)
	 {
	 	struct node *temp = start;
		while(temp->next)
		{
			temp = temp->next;
	 	}
		temp->next = head;
	}

	else {
		start = head;
	}
	return start;
}
struct node *getPoly(struct node *start) {
	int a, b, i, n;
	printf("Enter number of terms in equation: ");
	scanf("%d", &n);
	printf("Enter coefficient and exponent of each term in equation:-\n");
	for(i = 1; i <= n; i++) {
		printf("Term %d\nCoefficient: ", i);
		scanf("%d", &a);
		printf("Exponent: ");
		scanf("%d", &b);
		printf("\n");
		start = insNode(start, a, b);
	}
	printf("Entered polynomial:-\n");
	dispPoly(start);
	printf("\n");
	return start;
}
void mulPoly() {
	if(!eqn1 || !eqn2) {
		printf("0\n");
	}
	else {
		struct node *temp = eqn1, *temp2, *prev;
		int flag;
		while(temp) {
			temp2 = eqn2;
			while(temp2) {
				eqn3 = insNode(eqn3, (temp->coeff * temp2->coeff), (temp->exp + temp2->exp));
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		temp = eqn3;
		while(temp) {
			temp2 = temp->next;
			prev = temp;
			while(temp2) {
				if(temp->exp == temp2->exp) {
					temp->coeff += temp2->coeff;
					prev->next = temp2->next;
				}
				temp2 = temp2->next;
				prev = prev->next;
			}
			temp = temp->next;
		}
		dispPoly(eqn3);
	}
}

void main() 
{
	int ch;
	printf("Enter polynomial equation 1:-\n");
	eqn1 = getPoly(eqn1);
	printf("Enter polynomial equation 2:-\n");
	eqn2 = getPoly(eqn2);
	printf("\n\nResult of polynomial multiplication:-\n==============================\n");
	mulPoly();
	printf("\n");
}                            
