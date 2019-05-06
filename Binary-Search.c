#include<stdio.h>
#include<time.h>

int main(int argc,char *argv[])
{
	int n,i,e,mid=0,beg=0,last=0,flag=0,a[2000];
	double m;
	clock_t t1,t2;
	char *p;
	
	FILE *fp;		
  	fp=fopen("bs.dat","a");		
	
	n=strtol(argv[1], &p, 10);
	last=n;
	for(i=0;i<n;i++)
		a[i]=i;
	printf("\nEnter search element : ");
	scanf("%d",&e);
	
	t1=clock();
	if(beg==e)
    printf("Element found at pos : %d",0);
  else if(last==e)
	  printf("Element found at pos : %d",n-1);
	else
  {
    mid=(beg+last)/2;
   	while(flag!=1)
   	{
			if(a[mid]==e)
 			{	flag=1;
        printf("\nElement found at pos : %d",mid);
      }
      else if(a[mid]<e)
      {
				beg=mid;
  			mid=(beg+last)/2;                                      
   		}
			else if(a[mid]>e)
   		{
  			last=mid;
 				mid=(beg+last)/2;
 			}
		}
	}      
 	t2=clock();
	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\nTime Comp = %f\n",m);
	fprintf(fp,"%d   %f\n",n,m);
	fclose(fp);			
	return 0;
}   
