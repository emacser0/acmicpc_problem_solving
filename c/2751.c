#include <stdio.h>
int i,m=1e6,n,b[5000000],c[5000000];

int
main() {
  scanf("%d",&n);
  for(;n;) {
    scanf("%d",&b[n]);
    c[b[n--]+m]++;
  }
  for(;i<=m*2;i++) {
    for(;c[i];c[i]--) {
      printf("%d\n",i-m);
    }      
  }    
}
