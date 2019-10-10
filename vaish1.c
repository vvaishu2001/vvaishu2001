#include<stdio.h>
#include<stdlib.h>

int linear(int[], int, int);
int binary1(int[], int, int);
int binary2(int[], int, int, int);
void sort(int[], int);

void main(void){
	int ch, arr[100], n, i, a = -1, b = -1, c = -1, e;
	printf("\n\tEnter size of array\t");
	scanf("%d", &n);
	printf("\tEnter elements of array\t");
	for(i=0;i<n;++i)
		scanf("%d", &arr[i]);
	printf("\tEnter element to be searched\t");
	scanf("%d", &e);
	sort(arr, n);
	printf("\n\tSorted array ::\n");
	for(i=0; i<n; ++i)
		printf("%d ", arr[i]);
	printf("1. Linear search\n\t2. Binary (Iterative)\n\t3. Binary (Recursive)\n\t4. Exit\n\tEnter your choice\t");
	scanf("%d", &ch);
	switch(ch){
		case 1 : a = linear(arr, n, e);
				 if(a>0)
				 		printf("Ele found at pos %d\n",a);
				 else
				 		printf("Not found\n");
				 break;
		case 2 : c = binary1(arr, n, e);
				 if(c>0)
				 		printf("Ele found at pos %d\n",c);
				 else
				 		printf("Not found\n");
				 break;
		case 3 : b = binary2(arr, 0, n-1, e);
				 if(b>0)
				 		printf("Ele found at pos %d\n",b);
				 else 
				 		printf("Not found\n");
				 break;
		case 4 : exit(0);
				 break;
		default : printf("Invalid input");
	}
}

void sort(int arr[], int n){
	int i, j, temp;
	for(i=0; i<n-1; ++i){
		for(j=0; j<n-1-i; ++j){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int linear(int arr[], int n, int e){
	int i;
	for(i=0;i<n;++i){
		if(arr[i]==e)
			return i+1;
	}
	return -1;
}

int binary2(int arr[], int beg, int last, int e){
	int mid = (beg+last)/2;
	while(beg<=last){
		if(arr[mid]==e)
			return mid+1;
		else if(arr[mid]<e){
			beg = mid+1;
			return binary2(arr, beg, last, e);
		}
		else{
			last = mid-1;
			return binary2(arr, beg, last, e);
		}
	}
	return -1;
}
	
int binary1(int arr[], int n, int e){
	int beg = 0, last = n-1,mid;
	while(beg<last){
		 mid = (beg+last)/2;
		if(arr[mid]==e)
			return mid+1;
		else if(arr[mid]<e){
			beg = mid+1;
			break;
		}
		else{
			last = mid-1;
			break;
		}
	}
	return -1;
}

