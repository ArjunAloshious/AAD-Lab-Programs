#include<stdio.h>
#include<time.h>

void main()
{
	int k,a[12],i,n,e,flag=0,de=0;
	double m;
	clock_t t1,t2;
	printf("Enter limit of array : ");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	t1=clock();
	printf("Enter element to be removed : ");
	scanf("%d",&e);
	for(i=0;i<n;i++)
	{
		if(a[i]==e)
		{
	  		k=i;
	  		flag=1;
	  		de=a[i];
	  	}
	}
	if (flag==1)
	{
		for(i=k;i<n-1;i++)
  		a[i]=a[i+1];
  	a[i]='\0';
  	for(i=0;i<n-1;i++)
  		printf("%d ",a[i]);
  	}
  	else
	{
    		printf("Element not present\n");
	}
	flag=0;
	for(i=k;i<n;i++) 
	{
		if(a[i]>de)
		{
			printf("\nNext larger element is %d\n",a[i]);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nNo larger element\n");
	}
	t2=clock();
	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%f\n",m);
}
