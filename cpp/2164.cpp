#include <cstdio>
int n,queue[500000],s,e;
int
main() {
  scanf("%d",&n);
  e=n-1;
  for(int i=0;i<n;i++) {
    queue[i]=i+1;
  }
  while(s!=e) {
    queue[s]=0;
    s=(s+1)%n;
    e=(e+1)%n;
    queue[e]=queue[s];    
    s=(s+1)%n;    
  }
  printf("%d\n",queue[s]);
}
