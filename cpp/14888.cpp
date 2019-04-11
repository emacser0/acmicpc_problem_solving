#include <cstdio>
#define dfs(n,expr) if(rop[n]) {rop[n]--;_dfs(x+1,rop,sum expr nums[x]);rop[n]++;}
int i,n,nums[104],op[4],max=-1e9,min=1e9;
void _dfs(int x,int rop[4],int sum) {
  if(x==n) max=max>sum?max:sum,min=min<sum?min:sum;
  dfs(0,+);
  dfs(1,-);
  dfs(2,*);
  dfs(3,/);  
}
int
main() {  
  for(scanf("%d",&n);i<n;i++) scanf("%d",nums+i);
  for(i=0;i<4;i++) scanf("%d",op+i);
  _dfs(1,op,nums[0]);
  printf("%d\n%d\n",max,min);
}
