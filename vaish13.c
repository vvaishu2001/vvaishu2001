#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node* right;
  struct node* left;
}node;

node* parent;
node* root=NULL;
node* ptr;
node* p;
void insert(int x){
  node* newnode=(node*)malloc(sizeof(node));
  newnode->data=x;
  newnode->right=NULL;
  newnode->left=NULL;

  if(newnode==NULL){
    printf("No Space !!");
    return;
  }
  if(root==NULL){
    root=newnode;
  }
  else{
    ptr=root;
    int flag=0;
    while(ptr!=NULL && flag==0){
      if(x>ptr->data){
        parent=ptr;
        ptr=ptr->right;
      }
      else if(x<ptr->data){
        parent=ptr;
        ptr=ptr->left;
      }
      else flag==1;
    }
    if(flag==0){
      if(x>parent->data){
        parent->right=newnode;
      }
      else{
        parent->left=newnode;
      }
    }
    else{
      printf("Element exists!\n");
      return;
    }
  }
}

void delete(int key){
  int flag,cas;
  if(root==NULL){
    printf("BST EMPTY!\n");
    return;
  }
  ptr=root;
  flag=0;
  while(ptr!=NULL && flag==0){
    if(key>ptr->data){
      parent=ptr;
      ptr=ptr->right;
    }
    else if(key<ptr->data){
      parent=ptr;
      ptr=ptr->left;
    }
    else flag==1;
  }
  if (flag==0) {
    printf("Value Not found\n");
    return;
  }

  if (ptr->left==NULL && ptr->right==NULL) 
  		cas=1;
  else if (ptr->left!=NULL && ptr->right!=NULL)
    	cas=2;
  else
    	cas=3;

  if(cas==1){
    if(parent->right==ptr) parent->right==NULL;
    else parent->left==NULL;
    free(ptr);
  }

  else if (cas==2){
    if(parent->left==ptr){
      if(ptr->left==NULL) parent->left=ptr->right;
      else if (ptr->right==NULL) parent->left=ptr->left;
    }
    else if(parent->right==ptr){
      if(ptr->right==NULL) parent->right=ptr->left;
      else if(ptr->left==NULL) parent->right==ptr->right;
    }
  }

  else if (cas==3){
    node* succ=ptr->right;
    while(succ->left!=NULL){
      succ=succ->left;
    }
    int e=succ->data;
    delete(succ->data);
    ptr->data=e;
  }
}


void search(int key){
  if(root==NULL){
    printf("No such BST!");
    return;
  }
  ptr=root;
  int flag=0;
  while(ptr!=NULL && flag==0){
    if(key>ptr->data) ptr=ptr->right;
    else if (key<ptr->data) ptr=ptr->left;
    else flag=1;
  }
  if(flag==1) printf("Found\n");
  else printf("NOT Found\n");
}

void preorder(node* p){
  if(p!=NULL)
  {
  	printf("%d  ",p->data);
  	preorder(p->left);
  	preorder(p->right);
  }
}
void inorder(node* p){
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d ",p->data);
		inorder(p->right);
	}
}
void postorder(node* p){
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ",p->data);

	}
}
void traverse(){
	int x;
	printf("enter the display choice\n");
	scanf("%d",&x);
	if(x==1)
		preorder(p);
	else if(x==2)
		inorder(p);
	if(x==3)
		postorder(p);
}
void main()
{
	int ch,x,key,y;
    printf("1.insert\n\t2.delete\n\t3.search\n\t4.traversal\n\t5.exit");
	printf("enter the choice::\n");
	scanf("%d",&ch);
	switch(ch)
		{
			case 1:printf("enter the no. to be entered::");
				   scanf("%d",&x);
				   insert(x); 
				   break;
			case 2:printf("enter the key to be deleted::");
					scanf("%d",&key);
					delete(key);
				   break;
			case 3:printf("enter the element to be searched::");
					scanf("%d",&y);
					search(y);
				   break;
		    case 4:traverse();
		    	   break;
			case 5:exit(0);
			default: printf("\nWrong Choice!!");
		}
}

