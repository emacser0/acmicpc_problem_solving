#include <cstdio>
int t,n,k,c;
int
main() {
  scanf("%d",&t);
  for(int i=0;i<t;i++) {
    int cnt=0;
    scanf("%d%d",&n,&k);
    for(int j=0;j<n;j++) {
      scanf("%d",&c);
      while(c>=k) {
        c-=k;
        cnt++;
      }
    }
    printf("%d\n",cnt);
  }
}
