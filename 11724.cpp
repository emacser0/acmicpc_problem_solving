#include <cstdio>
int graph[1000][1000],visited[1000],n,m,u,v,cnt;
void dfs(int u) {
  for(int v=0;v<n;v++) {
    if(graph[u][v]&&(!visited[v])) {
      visited[v]=1;
      dfs(v);
    }
  }
}
int
main() {
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++) {
    scanf("%d%d",&u,&v);
    graph[u-1][v-1]=1;
    graph[v-1][u-1]=1;
  }  
  for(int u=0;u<n;u++) {
    if(!visited[u]) {
      dfs(u);
      cnt++;
    }    
  }
  printf("%d\n",cnt);
}
