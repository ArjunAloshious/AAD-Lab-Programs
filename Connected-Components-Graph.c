#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

void dfs_graph(int vert,int graph[V][V],bool visited[V])
{
  printf("%d ",vert);
  visited[vert]=true;
  for(int i=0;i<V;++i)
  {
    if(graph[vert][i] && !visited[i])
	  {
	    printf("-> ");
	    dfs_graph(i,graph,visited);
	  }
  }
}


void connected_components(int graph[V][V])
{
  bool visited[V];
  for(int i=0;i<V;++i)
  	visited[i]=false;
  for(int i=0;i<V;++i)
  {
    if(!visited[i])
	  {
	    dfs_graph(i,graph,visited);
	    printf("\n");
	  }
  }
}


int main()
{
  int mat[V][V]={{0,1,0,1,0},
								 {1,0,1,0,0},
								 {0,1,0,0,0},
								 {0,0,0,0,1},
								 {0,0,0,1,0}};
  printf("Adajcency matrix,\n");
  for(int i=0;i<V;++i)
  {
    for(int j=0;j<V;++j)
	    printf("%-7d",mat[i][j]);
    printf("\n");
  }
  printf("\nConnected Compents,\n");
  connected_components(mat);
  return 0;
}
