#include<stdio.h>
#include<stdlib.h>

void heapsort(int[], int);
void heapify(int[], int, int);

void main(){
	int a[50], n;
	printf("\tEnter the number of elements to be inserted\t");
    scanf("%d",&n);
	printf("\tEnter elements of array ::\t");
	for(int i=0;i<n;i++) 
		scanf("%d",&a[i]);
    heapsort(a,n-1);
    printf("\tSorted array ::\t");
    for(int i=0;i<n;i++) 
    	printf("%d  ",a[i]);
    printf("\n");
}

void heapsort(int a[], int n){
	int i, temp;
	for(i=n/2; i>=0; --i)
		heapify(a, n, i);
	for(i=n; i>0;--i){
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, i, 0);
	}
}

void heapify(int a[], int n, int i){
	int largest=i, l=2*i, r=2*i+1, temp;
	if(l<n && a[l]>a[largest])
		largest = l;
	if(r<n && a[r]>a[largest])
		largest = r;
	if(largest!=i){
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a, n, largest);
	}
}
