#include<stdio.h>
#include<limits.h>

#define V 5

typedef struct
{
	int first,second,weight;
}Edges;


int lsearch(int arr[],int c,int ele)
{
  for(int i=0;i<c;++i)
  {
    if(arr[i]==ele) 
      return 1;
  }
  return 0;
}

int check_inserted_arr(int arr[],int c,int x,int y)
{
  return lsearch(arr,c,x) && lsearch(arr,c,y);
}


int check_inserted_edge(Edges e[],int n,int x,int y)
{
  for(int i=0;i<n;++i)
  {
    if((e[i].first==x || e[i].first==y) && (e[i].second==x || e[i].second==y))
	    return 1;
  }
  return 0;
}


int convert(int mat[][V],Edges e[])
{
  int flag,x,y,visited[20],edge_c=0;
  for(int i=0;i<20;++i)
    visited[i]=-2;
  for(;;)
  {
    flag=x=y=0;
    for(int i=0;i<V;++i)
	  {
	    for(int j=0;j<V;++j)
	    {
	      if(!check_inserted_edge(e,edge_c,i,j) && mat[i][j] && mat[i][j]!=INT_MAX)
				{
					e[edge_c].first=i;
					e[edge_c].second=j;
					e[edge_c].weight=mat[i][j];
					++edge_c;
					flag=1;
				}
	    }
		}
    if(!flag) 
      return edge_c;
  }  
}


void heapify(Edges e[],int n,int root)
{
  Edges tmp;
  int largest = root;
  int l = 2*root + 1;
  int r = 2*root + 2;
  if (l < n && e[l].weight < e[largest].weight) 
    largest = l; 
  if (r < n && e[r].weight < e[largest].weight) 
    largest = r; 
  if (largest != root) 
  { 
    tmp=e[root];
    e[root]=e[largest]; 
    e[largest]=tmp;
    heapify(e, n,largest); 
  } 
}

int insert(int arr[],int n,int x,int y)
{
  if(!lsearch(arr,n,x))
    arr[n++]=x;
  if(!lsearch(arr,n,y))
    arr[n++]=y;
  return n;
}


int main()
{
  int mat[V][V] = {{0, 9, 75, 0, 0},
		   {9, 0, 95, 19, 42},
		   {75, 95, 0, 51, 66},
		   {0, 19, 51, 0, 31},
		   {0, 42, 66, 31, 0}};

  Edges e[20],mst[20],tmp;
  int mst_c=0,visit_c=0,edge_c,visited[20];
  edge_c=convert(mat,e);
  for (int i = edge_c / 2 ; i >= 0; i--) 
    heapify(e,edge_c, i); 
  for(int i=edge_c-1;i>=0;--i)
  {
    tmp=e[0];
    e[0]=e[i];
    e[i]=tmp;
    heapify(e,i,0);
    if(!check_inserted_arr(visited,visit_c,e[i].first,e[i].second))
		{
			mst[mst_c].first=e[i].first;
			mst[mst_c].second=e[i].second;
			mst[mst_c].weight=e[i].weight;
			visit_c=insert(visited,visit_c,e[i].first,e[i].second);
			++mst_c;
		}
  }
  printf("Adjacency matrix :- \n");
  for(int i=0;i<V;++i)
  {
    for(int j=0;j<V;++j)
		{
		  if(mat[i][j]==INT_MAX) 
		    printf("%d ",-1);	
	  	else 
	  	  printf("%d ",mat[i][j]);
		}
    printf("\n");
  }  
  printf("\nMinimum Spanning Tree :- \n");
  
  for(int i=0;i<mst_c;++i) 
  	printf("%d -> %d : %d\n",mst[i].first,mst[i].second,mst[i].weight);
  return 0;
}
