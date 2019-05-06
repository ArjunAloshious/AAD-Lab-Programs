#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char *argv[])
{
	printf("\n\n..........Selection Sort Program..........\n\n");
	int x,i,j,k,temp,lowest,a[1000],b[1000],c[1000],n;
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
	for(i=0;i<n-1;i++)
	{
		lowest=i;
 		for(j=i+1;j<n;j++)
 		{
 			if(a[j]<a[lowest])
		  	lowest=j;
 	 	}
 	 	temp=a[i];
		a[i]=a[lowest];
		a[lowest]=temp;
	}
	t2=clock();
  	m=(double)(t2-t1)/CLOCKS_PER_SEC;
  	printf("Time Comp = %f\n",m);
	fprintf(fp,"%d   %f\n",n,m);	


	printf("\nFor array in ascending order\n\n");
	for(i=1;i<=n;i++)
	{
		b[i]=i;
	}	
	t3=clock();
	for(i=0;i<n-1;i++)
	{
		lowest=i;
 		for(j=i+1;j<n;j++)
 		{
 			if(a[j]<a[lowest])
		  	lowest=j;
		}
 	 	temp=a[i];
		a[i]=a[lowest];
		a[lowest]=temp;
	}
	t4=clock();
	m=(double)(t4-t3)/CLOCKS_PER_SEC;
 	printf("Time Comp = %f\n",m);

	printf("\nFor array in descending order\n\n");
	for(i=n,j=0;i>=1,j<n;i--,j++)
	{
		c[j]=i;
	}
	t5=clock();
	for(i=0;i<n-1;i++)
	{
		lowest=i;
 		for(j=i+1;j<n;j++)
 		{
 			if(a[j]<a[lowest])
		  	lowest=j;
		}
 	 	temp=a[i];
		a[i]=a[lowest];
		a[lowest]=temp;
	}
	t6=clock();
  	m=(double)(t6-t5)/CLOCKS_PER_SEC;
  	printf("Time Comp = %f\n",m);
	fclose(fp);				
	return 0;
}
