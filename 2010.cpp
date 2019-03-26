#include <cstdio>
int n,t,sum;
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&t);
    sum+=i<n-1?t-1:t;
  }
  printf("%d\n",sum);
}
