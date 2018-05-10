#include <stdio.h>
int i,m=10001,c[10001],n;

int
main() {
  for(scanf("%d",&n);n;n--) {
    scanf("%d",&i);c[i]++;}
  for(i=1;i<m;i++) {
    for(;c[i];c[i]--) {
      printf("%d\n",i);
    }      
  }    
}
