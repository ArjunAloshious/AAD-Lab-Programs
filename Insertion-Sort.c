#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char *argv[])
{
	printf("\n\n..........Insertion Sort Program..........\n\n");
	int x,i,j,k,a[1000],b[1000],c[1000],n;
	double m;
	char *p;

	FILE *fp;			//file
  	fp=fopen("ins.dat","a");	//file

	clock_t t1,t2,t3,t4,t5,t6;
	n=strtol(argv[1], &p, 10);
	for(i=0;i<n;i++)
	{
		a[i]=rand();	
	}
	printf("\nFor random array\n");
	t1=clock();
	for(i=1;i<n;i++)
 	{	
 		x=a[i];
 		for(j=i-1;j>=0 && x<a[j];j--)
 		{
 			a[j+1]=a[j];
 		}
		a[j+1]=x;
	}
	t2=clock();
  	m=(double)(t2-t1)/CLOCKS_PER_SEC;
  	printf("Time Comp = %f\n",m);
	fprintf(fp,"%d   %f\n",n,m);	//file


	printf("\nFor array in ascending order\n");
	for(i=1;i<=n;i++)
	{
		b[i]=i;
	}	
	t3=clock();
	for(i=1;i<n;i++)
 	{	
 		x=a[i];
 		for(j=i-1;j>=0 && x<a[j];j--)
 		{
 			a[j+1]=a[j];
 		}
		a[j+1]=x;
	}
	t4=clock();
  	m=(double)(t4-t3)/CLOCKS_PER_SEC;
  	printf("Time Comp = %f\n",m);

	printf("\nFor array in descending order\n");
	for(i=n,j=0;i>=1,j<n;i--,j++)
	{
		c[j]=i;
	}
	t5=clock();
	for(i=1;i<n;i++)
 	{	
 		x=a[i];
 		for(j=i-1;j>=0 && x<a[j];j--)
 		{
 			a[j+1]=a[j];
 		}
		a[j+1]=x;
	}
	t6=clock();
 	m=(double)(t6-t5)/CLOCKS_PER_SEC;
 	printf("Time Comp = %f\n",m);
	
	fclose(fp);			//file	
	return 0;
}
