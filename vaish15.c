#include<stdio.h>
#include<stdlib.h>
void quicksort(int[],int,int);
void mergesort(int[],int,int);
void merge(int[],int,int,int);

void quicksort(int a[5],int lb,int ub){
   int i, j, pivot, temp;

   if(lb<ub){
      pivot=lb;
      i=lb;
      j=ub;

      while(i<j){
         while(a[i]<=a[pivot]&&i<ub)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,lb,j-1);
      quicksort(a,j+1,ub);

   }
}

void mergesort(int a[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

void merge(int a[],int lb,int mid,int ub){
    int i=lb,j=mid+1,temp[ub-lb+1],k=0;
    while(i<=mid && j<=ub){
        if(a[i]>=a[j]){
            temp[k]=a[j];
            k++;
            j++;
        }
        else{
            temp[k]=a[i];
            k++;
            i++;
        }
    }
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=ub){
        temp[k]=a[j];
        j++;
        k++;
    }
    i=0;
    j=lb;
    while(i<k){
        a[j]=temp[i];
        i++;
        j++;
    }
}

int main(){
   int i, n, a[5],ch;

   printf("enter the limit: ");
   scanf("%d",&n);

   printf("Enter %d elements: ", n);
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   while(1)
   {
   	printf("\n1.quicksort\n2.merge sort\nenter the choice::");
   	scanf("%d",&ch);
   	if(ch==1)
   	{ 
   		quicksort(a,0,n-1);
   	}
   	else
   	{
        	mergesort(a,0,n-1);
   	}
   	printf("after Sorting the elements: ");
   	for(i=0;i<n;i++)
      	printf(" %d\n",a[i]);

   	return 0;
}
}

