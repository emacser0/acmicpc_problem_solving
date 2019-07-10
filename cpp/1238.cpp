#include <stdio.h>
int N,M,X,graph[1004][1004],a,b,c,r;
int _min(int a, int b)
{
  return a<b?a:b;
}
int _max(int a, int b)
{
  return a>b?a:b;
}
void init()
{
  for(int i=0;i<1004;i++)
  {
    for(int j=0;j<1004;j++)
    {
      graph[i][j]=1e8;
    }
    graph[i][i]=0;
  }
}
int main()
{
  init();
  scanf("%d%d%d",&N,&M,&X);
  for(int i=0;i<M;i++)
  {
    scanf("%d%d%d",&a,&b,&c);
    graph[a][b]=c;
  }
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
      if(graph[j][i]<1e8)
      {
        for(int k=1;k<=N;k++)
        {
          graph[j][k]=_min(graph[j][k],_min(graph[j][i]+graph[i][k],1e8));
        }
      }
    }
  }
  for(int i=1;i<=N;i++)
  {
    r=_max(r,graph[i][X]+graph[X][i]);
  }
  printf("%d\n",r);
}
