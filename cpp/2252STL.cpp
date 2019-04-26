#include <stdio.h>
#include <vector>
int N,M,a,b,visited[32004],p[32004],rstack[32004],rsi;
std::vector<int> graph[32004];
void dfs(int x) {
  for(int i=0;i<graph[x].size();++i){
    if(!visited[graph[x][i]]) {
      visited[graph[x][i]]=1;
      dfs(graph[x][i]);
    }
  }
  rstack[rsi++]=x;
}
int main() {
  scanf("%d%d",&N,&M);
  for(int i=0;i<M;i++) {
    scanf("%d%d",&a,&b);
    graph[a].push_back(b);
    p[b]++;
  }
  for(int i=1;i<=N;i++) {
    if(!p[i]&&!visited[i]) {
      visited[i]=1;
      dfs(i);
    }
  }
  for(int i=N-1;i>=0;i--) {
    printf("%d ",rstack[i]);
  }
  puts("");
}
