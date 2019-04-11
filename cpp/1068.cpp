#include <cstdio>
int n,tree[51],root,d,c;
void
delete_node(int d) {
  tree[d]=-2;
  for(int i=0;i<n;i++) {
    if(tree[i]==d) {
      delete_node(i);
    }
  }
}
void
dfs(int x) {
  int cnd=0;
  for(int i=0;i<n;i++) {
    if(tree[i]==x) {
      dfs(i);
      cnd=1;
    }
  }
  if(cnd==0) {
    c++;
  }
}
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&tree[i]);
    if(tree[i]==-1) {
      root=i;
    }
  }
  scanf("%d",&d);
  delete_node(d);
  if(tree[root]!=-2) {
    dfs(root);
  }
  printf("%d\n",c);
}
