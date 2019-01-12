#include <cstdio>
int t,n,c2,c5;
int
main() {
  scanf("%d",&t);
  for(int i=0;i<t;c2=c5=0,i++) {
    scanf("%d",&n);
    for(int i=2;i<=n;i*=2) {
      c2+=n/i;
    }
    for(int i=5;i<=n;i*=5) {
      c5+=n/i;
    }
    printf("%d\n",c2<c5?c2:c5);
  }
}
