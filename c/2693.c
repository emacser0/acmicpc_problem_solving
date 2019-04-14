#include <stdio.h>
#define swap(x,y) {t=x;x=y;y=t;}
int T,a[10],t;
void insert(int x) {
  for(int i=x;i>0;i--) {
    if(a[i-1]>a[i]) {
      swap(a[i-1],a[i]);
    }
  }
}
int
main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    for(int j=0;j<10;j++) {
      scanf("%d",a+j);
      insert(j);
    }
    printf("%d\n",a[7]);
  }
}
