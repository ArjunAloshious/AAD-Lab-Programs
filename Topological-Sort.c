#include <stdio.h>
#include <stdbool.h>

#define V 4

void disp_mat(int mat[][V])
{
  for(int i=0;i<V;++i)
    {
      for(int j=0;j<V;++j)
				printf("%-7d",mat[i][j]);
      printf("\n");
    }
}


int main()
{
  int mat[V][V]={{0,1,1,0},
								 {0,0,0,1},
								 {0,0,0,1},
								 {0,0,0,0}};
  bool visited[V];
  int degree[V];
  for(int i=0;i<V;++i)
  	visited[i]=degree[i]=0;
  for(int i=0;i<V;++i)
    for(int j=0;j<V;++j)
      degree[i]+=mat[j][i];
  printf("Adjacency matrix,\n");
  disp_mat(mat);
  printf("\nTopological sort,\n");
  for(int i=0;i<V;++i)
  {
  	if(!degree[i] && !visited[i])
		{
		  printf("%d ",i);
		  visited[i]=true;
		}
    for(int j=0;j<V;++j)
			if(mat[i][j]==1)
	 			degree[j]--;
  }
  printf("\n");
  return 0;
}
