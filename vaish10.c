#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front=-1;
int rear=-1;
void enqueue(int a[])
{
   if(rear>=MAX-1)
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
         rear++;
      }
      printf("Enter the element to be inserted: ");
      scanf("%d",&a[rear]);
   }
}
void dequeue(int a[])
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
         front++;
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
     else 
     {
         for(i=front;i<=rear;i++)
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
        
		printf("\n1. Enqueue\n 2.Dequeue\n 3.Display\n4. Exit\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: enqueue(a);
				break;
			case 2: dequeue(a);
				break;
			case 3: display(a);
				break;
			case 4: exit(1);
			default: printf(" Wrong choice ");
		}
	}while(n>=1&&n<=4);
}

