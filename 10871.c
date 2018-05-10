#include <stdio.h>
int n,x,t;

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
