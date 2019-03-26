#include <cstdio>
int n,t,a[2004];
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&t);
    a[t+1000]=1;    
  }
  for(int i=-1000;i<=1000;i++) {
    if(a[i+1000]) printf("%d ",i);
  }
  puts("");
}
