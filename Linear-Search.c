#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char *argv[])
{
	int i,n,a[2000],s,f=0;
	double m;
	char *p;
	clock_t t1,t2;
	n=strtol(argv[1], &p, 10);
	FILE *fp;			
  	fp=fopen("ls.dat","a");		
	
	for(i=1;i<=n;i++)
	  a[i]=i;

	printf("\nEnter search element : ");
	scanf("%d",&s);
		t1=clock();
 	for(i=0;i<n;i++)
 	{
 		if(a[i]==s)
 		{
 		  	f=1;
 			printf("\nElement found at position : %d\n",i);
		}
	}
	if(f!=1)
	{
		printf("\nElement not found\n");
	}
	t2=clock();
	m=(double)(t2-t1)/CLOCKS_PER_SEC;
  	printf("Time Comp = %f\n",m);
	fprintf(fp,"%d   %f\n",n,m);	
	fclose(fp);			
	return 0;
}
