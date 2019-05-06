#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int* a, int* b) 
{ 
   	int t = *a; 
    	*a = *b; 
	*b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high];   
	int i = (low - 1); 
	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] <= pivot) 
		{ 
			i++;   
		    	swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
   	} 
} 

int main(int argc,char *argv[])
{
	printf("\n\n..........Quick Sort Program..........\n\n");
   	int x,i,j,k,a[1000],b[1000],c[1000],n;
  	double m;
  	char *p;

 	FILE *fp;			
    	fp=fopen("sel.dat","a");	
	
    	clock_t t1,t2,t3,t4,t5,t6;
   	n=strtol(argv[1], &p, 10);
	for(i=0;i<n;i++)
	{
		a[i]=rand();	
    	}
  	printf("\nFor random array\n\n");
   	t1=clock();    
    	quickSort(a, 0, n-1); 
    	t2=clock();
   	m=(double)(t2-t1)/CLOCKS_PER_SEC;
   	printf("\nTime Comp = %f\n",m);
    	fprintf(fp,"%d   %f\n",n,m);	
     
	printf("\nFor array in ascending order\n\n");
	for(i=1;i<=n;i++)
	{
		b[i]=i;
	}	
	t3=clock();
	quickSort(b, 0, n-1); 
	t4=clock();
	m=(double)(t4-t3)/CLOCKS_PER_SEC;
	printf("\nTime Comp = %f\n",m);

	printf("\nFor array in descending order\n\n");
	for(i=n,j=0;i>=1,j<n;i--,j++)
	{
		c[j]=i;
	}
	t5=clock();
	quickSort(c, 0, n-1); 
	t6=clock();
  	m=(double)(t6-t5)/CLOCKS_PER_SEC;
  	printf("Time Comp = %f\n",m);
	fclose(fp);				
	return 0; 
}
