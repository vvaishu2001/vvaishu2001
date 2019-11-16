#include<stdio.h>
#define max 10
int mat[max][max],a[max],q[max];
int n,r=-1,f=0; 
void DFS(int i,int vs[])
{
  if(i!=n)
    {
      printf("\t%d",a[i]);
      vs[i]=1;
      for(int j=0;j<n;++j)
	if(!vs[j]&&mat[i][j])
	  DFS(j,vs);
    }
} 
void BFS(int i,int vs[])
  
{
  for(int j=0;j<n;++j)
    if(mat[i][j] && !vs[j])
      q[++r]=a[j];
  if(f<=r)
    {
      vs[f]=1;
      BFS(q[f++],vs);
    }
}
	     
 
  
int main(void)
{
  int i,j,ch;
  int vs[max]={0};
  printf("\nEnter the no.of nodes: ");
  scanf("%d",&n);
  for(i=0;i<n;++i)
    {
      printf("\nEnter the elements: ");
      scanf("%d",&a[i]);
    }
  printf("\nEnter the adjacency matrix:");
  for(i=0;i<n;++i)
    for(j=0;j<n;++j)
      {
	scanf("%d",&mat[i][j]);
      }
  while(1)
    {
      printf("\n\t\t1.DFS\n\t\t2.BFS\n\t\t3.EXIT\n\tSelect the mode of traversal: ");
      scanf("%d",&ch);
      for(i=0;i<n;++i)
	  vs[i]=0;
     if(ch==3)
	break;
      else if(ch==1)
	DFS(0,vs);
       else if(ch==2)
	 {
	   BFS(0,vs);
	   for(i=0;i<n;++i)
	     {
	       if(vs[i])
		 {
		   printf("%d\t",a[i]);
		 }
	     }
	 }
      else
	printf("\nInavalid choice");
    }
}
