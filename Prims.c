#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

//#define V 5
int main()
{
	int min=INT_MAX,edges=0,x=0,y=0; 
	int V;
	int mat[10][10];
	printf("Enter size : ");
	scanf("%d",&V);/*
	int mat[V][V] = {
	{0, 9, 75, 0, 0},
	{9, 0, 95, 19, 42},
	{75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
  };*/
 printf("Enter elements : ");
  for(int i=0;i<V;i++)
 	 for(int j=0;j<V;j++)
 		scanf("%d",&mat[i][j]); 
  bool selected[V];
	selected[0]=true;
	for(int i=0;i<V;++i) 
		selected[i]=false;
	printf("Adjacency matrix :-\n");
	for(int i=0;i<V;++i)
	{
		for(int j=0;j<V;++j)
		{
			if(mat[i][j]==INT_MAX) printf("%d ",-1);
			else printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\nMinimum spanning tree :-\n");
	for(int i=0;i<V-1;++i)
	{
		x=0,y=0,min=INT_MAX;
		for(int j=0;j<V;++j)
		{
			if(selected[j])
			{
				min=INT_MAX;
				for(int k=0;k<V;++k)
				{
					if(!selected[k] && mat[j][k])
					{
						if(min>mat[j][k])
						{
							min=mat[j][k];
							x=j;y=k;
						}
					}
				}
			}
		}
		printf("%d -> %d : %d\n",x,y,mat[x][y]);
		selected[y]=true;
	}
	return 0;
}
