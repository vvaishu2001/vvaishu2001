#include<stdio.h>
#include<stdlib.h>
#define Max 10
void ins(int);
void disp();
int h[Max];

void main()
{
	int c,n,i,j;
	for(j=0;j<Max;j++)
		h[j]=-1;
	while(1)
	{
		printf("1.insert\n\t2.display\n\t3.exit\n\tenter the choice::");
		scanf("%d",&c);
		if(c==1)
		{
			printf("\tEnter element to be inserted\t");
			scanf("%d", &n);
		    ins(n);
		}
		else if (c==2)
		{
			disp();
		
		}
		else 
		{
			exit(0);
		}
}
}

void ins(int n)
{
	int i=n%Max;
	int flag=0;
	if(h[i]==-1)
		h[i]=n;
	else
	{
		int j=i+1;
		while((flag==0)&&(j!=i))
		{
			if(h[i]==n);
			{
				flag==2;
				
			}
			if(h[j]==-1)
			{
				flag=1;
			}
			j=(j+1)%Max;
		}
		if(flag==0)
			printf("full\n");
		else if(flag==2)
			printf("element is present\n");
		else
			h[j]=n;
	}
}
void disp()
{
	int i;
	for(i=0;i<Max;++i)
		if(h[i]==-1)
	      	continue;
		else
			printf("%d-%d\n",i,h[i]);
	
}	
		
