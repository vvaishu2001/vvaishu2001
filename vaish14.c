#include<stdio.h>
#include<stdlib.h>
#define max 5;
#define n 6;
int top=-1, s[max];
int r=-1,f=-1;
int vs[n]=0;
void main()
{	int ch;
	printf("1.DFS\n\t2.BFS\n\t")
	printf("enter the option::%d");
	scanf("%d",&ch);
	if(ch==1)
	{
		return DSF();
	}
	else if(ch==2)
	{
		return BFS();
	}
	else 
	{
		return 0;
	}
}

void stack()
{
int val;
if(top==max-1)
{
printf("\n stack is full");
}
else
{
printf("\n enter the source vertex::%d\n")
scanf("%d",&val);
top++;
s[top]=val;
}
}

void pop()
{
if(top==-1)
printf("\n empty");
else
{
top--;
}
}
	
void enqueue(int q[])
{
if(r>=max-1)
{
printf("queue is full");
}
else
{
if(f==-1)
{
f=0;
r=0;
}
else
r++;
}
printf("enter the source vertex::\n");
scanf("%d",q[r]);
}

void dequeue()
{
if(f==-1)
printf("empty");
else
{
if(f==r)
{
f--;
r--;
}
else
f++;
}
}

void DFS()
{
int v,w;
v=push();
while(top!=-1)
{
v=pop();
if(vs[v]==0)
{
print v;
vs[v]=1;
}
while(w=adj(v))
{
w=push();
}
}
}

void BFS()
{
vs[n]=1;
enqueue(s[n]);
while(f==-1);
{
vc=dequeue();
while(w=adj(v))
{
if (vs[v]==0)
printf("%d",v);
}
enqueue(w[n]);
vs[w]=1;
}
}




















