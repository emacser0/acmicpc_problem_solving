#include <cstdio>
int n1,n2,a,b,graph[104][104],visited[104],cnt;
void dfs(int x) {
  for(int i=0;i<n1;i++) {
    if(graph[x][i]&&!visited[i]) {
      visited[i]=1;
      dfs(i);
      cnt++;
    }
  }
}
int
main() {
  scanf("%d%d",&n1,&n2);
  for(int i=0;i<n2;i++) {
    scanf("%d%d",&a,&b);
    graph[a][b]=graph[b][a]=1;
  }
  dfs(1);
  printf("%d\n",cnt);
}
