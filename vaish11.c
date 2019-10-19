#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front=-1;
int rear=-1;
void push(int a[])
{
   if(front==(rear+1)%MAX)
   {
      printf("queue is full");
   }
   else
   {
      if(front==-1)
      {
         front=0;
         rear=0;
      }
      else
      {
         rear=(rear+1)%MAX;
      }
      printf("Enter the element: ");
      scanf("%d",&a[rear]);
   }
}
void pop(int a[])
{
   if(front==-1)
   {
      printf("queue is empty");
   }
   else
   {
      printf("deleted element is %d",a[front]);
      if(front==rear)
      {
         front=-1;
         rear=-1;
      }
      else
      {
         front=(front+1)%MAX;
      }
   }
}
void display(int a[])
{
   int i;
   if(front==-1 && rear==-1)
   {
     printf("queue is empty");
   }
   else if(front<rear)
   {
      for(i=front;i<=rear;i++)
      {
         printf("%d\n",a[i]);
      }
   }
   else
   {
      for(i=front;i<MAX;i++)
      {
         printf("%d\n",a[i]);
       }
      for(i=0;i<=rear;i++)
      {
         printf("%d\n",a[i]);
      }
   }
}   
void main()
{
   int a[MAX];
   int n;
   do
	{
        
		printf("\n1.ENQUEUE\n 2.DEQUEUE\n 3.Display\n4. Exit\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case  1: push(a);
				break;
			case 2: pop(a);
				break;
			case 3: display(a);
				break;
			case 4: exit(1);
			default: printf(" Wrong choice ");
		}
	}while(n>=1&&n<=4);
}


