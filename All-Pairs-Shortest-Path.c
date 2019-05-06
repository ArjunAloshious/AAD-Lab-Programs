#include <stdio.h>

#define V 4
#define INF 9999

void disp_mat(int mat[][V])
{
  for(int i=0;i<V;++i)
  {
  	for(int j=0;j<V;++j)
		mat[i][j]==INF?printf("%-7s","INF"):printf("%-7d",mat[i][j]);
      	printf("\n");
  }
}  

int main()
{
  int mat[V][V]={{0,5,INF,10}, 
                 {INF,0,3,INF}, 
		 {INF,INF,0,1}, 
		 {INF,INF,INF,0}};
  printf("Adjacency matrix : \n");
  disp_mat(mat);
  for(int i=0;i<V;++i)
  {
	for(int j=0;j<V;++j)
	{
		for(int k=0;k<V;++k)
		{
			if(mat[j][k]>mat[j][i]+mat[i][k])
			{
				mat[j][k]=mat[j][i]+mat[i][k];
			}
		}
	}
  }
  printf("\nShortest paths : \n");
  disp_mat(mat);
  return 0;
}
