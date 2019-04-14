#include <stdio.h>
#include <string.h>
int n,v,s,m,mc,c[1001];
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++,m=0,mc=0) {
    scanf("%d",&v);
    for(int j=0;j<v;j++) {
      scanf("%d",&s);
      c[s]++;
    }
    for(int i=0;i<1001;i++) {
      if(c[i]>mc) {
        mc=c[i];
        m=i;
      }
    }
    printf("%d\n",m);
    memset(c,0,1001*sizeof(int));
  }
}
