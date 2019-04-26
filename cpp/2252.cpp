#include <stdio.h>
struct gstack{
  gstack *next;
  int x;
};
int N,M,a,b,visited[32004],p[32004],rstack[32004],rsi;
gstack *graph[32004];
gstack* insert(gstack *s, int x) {
  gstack *ns=new gstack();
  ns->x=x;
  ns->next=s;
  return ns;
}
void dfs(int x) {
  gstack *si=graph[x];
  while(si->next!=NULL) {
    if(!visited[si->x]) {
      visited[si->x]=1;
      dfs(si->x);
    }
    si=si->next;
  }
  rstack[rsi++]=x;
}
int main() {
  scanf("%d%d",&N,&M);
  for(int i=1;i<=N;i++) {
    graph[i]=new gstack();
    graph[i]->next=NULL;
  }
  for(int i=0;i<M;i++) {
    scanf("%d%d",&a,&b);
    graph[a]=insert(graph[a],b);
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
