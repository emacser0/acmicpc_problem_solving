#include <stdio.h>
int i,c[10],n,r=1;

int
main(){
  for(;~scanf("%d",&n);) {
    r*=n;
  }    
  for(;r;r/=10) {
    c[r%10]++;
  }    
  for(;i<10;) {
    printf("%d\n",c[i++]);
  }    
}
