#include <stdio.h>
int t,b;
int main() {
  for(;(b=getchar())>10;) {
    t+=b<80?(b-65)/3+3:b<84?8:b<87?9:10;
  }    
  printf("%d",t);}
