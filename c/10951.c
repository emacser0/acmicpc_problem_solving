#include <stdio.h>
int a,b,ret[10000],i=0;

int
main() {  
  for(;~scanf("%d%d",&a,&b);) {
    ret[i++]=a+b;
  }
  for(int j=0;j<i;j++) {
    printf("%d\n",ret[j]);
  }   
}
