#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,x,t;
char buf[99999],buf2[99];

int
main() {  
  scanf("%d %d",&n,&x);
  for(int i=0;i<n;i++) {
    scanf("%d",&t);
    if(t<x) {
      printf("%d ",t);
    }
  }
  printf("\n");
}
