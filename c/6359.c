#include <stdio.h>
#include <string.h>
int r[104],T,n,c;
int
main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%d",&n);
    memset(r,1,101*sizeof(int));
    c=0;
    for(int j=2;j<=n;j++) {
      for(int k=j;k<=n;k++) {
        if(k%j==0)r[k]=!r[k];
      }
    }
    for(int j=1;j<=n;j++) {
      if(r[j])c++;
    }
    printf("%d\n",c);
  }
}
