#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}Node;
int size;
void ins(int data,Node* a[]){
	Node *newnode=(Node*)malloc(sizeof(Node));
	newnode->data=data;
	newnode->link=NULL;
	int pos=data%size;
	if(!a[pos]){
		a[pos]=newnode;
	}
	else{
		Node *temp=a[pos];
		while(temp->link){
			temp=temp->link;
		}
		temp->link=newnode;
	}
}
int search(int key,Node* a[]){
	int pos=key%size,flag=0;
	Node *temp=a[pos];
	while(temp){
		if(temp->data==key){
			flag=1;
			break;
		}
		temp=temp->link;
	}
	return flag;
}
void display(Node* a[]){
	for(int i=0;i<size;i++){
		if(a[i]){
			printf("Elements in position %d are:\n",i);
			Node *temp=a[i];
			while(temp){
				printf("%d ",temp->data);
				temp=temp->link;
			}
		}
		printf("\n");
	}
	printf("\n");
}
void main(){
	printf("Enter the size of array:\n");
	scanf("%d",&size);
        Node* a[size];
        for(int i=0;i<size;i++){
                a[i]=NULL;
        }
        int choice,elem;
        while(1){
                printf("Enter the choice 1.ins 2.Search 3.Display 4.Exit\n");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("Enter the element to be insed:\n");
                                scanf("%d",&elem);
                                ins(elem,a);
                                break;
                        case 2:
                                printf("Enter the element to be searched for:\n");
                                scanf("%d",&elem);
                                if(search(elem,a)){
                                        printf("Element found\n");
                                }
                                else{
                                        printf("Element not found\n");
                                }
                                break;
                        case 3:
                                display(a);
                                break;
                        case 4:
                                printf("Exiting.....\n");
                                exit(0);
                        default:
                                printf("Wrong choice\n");
                                continue;
                }
        }
}

