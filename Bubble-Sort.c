#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char *argv[])
{
	printf("\n\n..........Bubble Sort Program..........\n\n");
	int i,j,k,a[1000],b[1000],c[1000],temp,n;
	double m;
	char *p;

	FILE *fp;			
  	fp=fopen("bb.dat","a");		

	clock_t t1,t2,t3,t4,t5,t6;
	n=strtol(argv[1], &p, 10);
	for(i=0;i<n;i++)
	{
		a[i]=rand();	
	}
	printf("\nFor random array\n");
	t1=clock();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{ 
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				
			}		
		}
	}
	t2=clock();
	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("Time Comp = %f\n",m);
	fprintf(fp,"%d   %f\n",n,m);	


	printf("\nFor array in ascending order\n");
	for(i=1;i<=n;i++)
	{
		b[i]=i;
	}	
	t3=clock();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{ 
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}		
		}
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
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{ 
			if(c[j]>c[j+1])
			{
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
			}		
		}
	}
	t6=clock();
  	m=(double)(t6-t5)/CLOCKS_PER_SEC;
  	printf("Time Comp = %f\n",m);
	fclose(fp);			
	return 0;
}
