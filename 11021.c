#include <stdio.h>
int t,a,b;

int
main() {  
  scanf("%d",&t);
  for(int i=0;i<t;i++) {
    scanf("%d %d",&a,&b);
    printf("Case #%d: %d\n",i+1,a+b);
  }
}
