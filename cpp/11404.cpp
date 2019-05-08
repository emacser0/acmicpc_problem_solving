#include <cstdio>
#define MIN(a,b) a<b?a:b
int n,m,a,b,c,graph[104][104];
int
main() {
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {      
      graph[i][j]=i==j?0:2e9;
    }
  }  
  for(int i=0;i<m;i++) {
    scanf("%d%d%d",&a,&b,&c);
    graph[a-1][b-1]=MIN(graph[a-1][b-1],c);
  }
  int value;
  for(int j=0;j<n;j++) {
    for(int i=0;i<n;i++) {
      for(int k=0;k<n;k++) {
        if(graph[i][j]<2e9&&graph[j][k]<2e9) {
          value = graph[i][j]+graph[j][k];
          graph[i][k]=MIN(graph[i][k],value);
        }        
      }
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      printf("%d ",(graph[i][j]>=2e9)||(i==j)?0:graph[i][j]);
    }
    puts("");
  }
}
