#include <stdio.h>
#include <string.h>
int N,M,g[2004][2004],visited[2004],m[2004],s,x,cnt;
int dfs(int x) {
  if(visited[x]) return 0;
  visited[x]=1;
  for(int i=0;g[x][i]&&i<N;i++) {
    if(!m[g[x][i]]||dfs(m[g[x][i]])) {
      m[g[x][i]]=x;
      return 1;
    }
  }
  return 0;
}
int main() {
  scanf("%d%d",&N,&M);
  for(int i=1;i<=N;i++) {
    scanf("%d",&s);
    for(int j=0;j<s;j++) {
      scanf("%d",&x);
      g[i][j]=x;
    }
  }
  for(int i=1;i<=N;i++) {
    memset(visited,0,2001*sizeof(int));
    if(dfs(i))cnt++;
  }
  printf("%d\n",cnt);
}
