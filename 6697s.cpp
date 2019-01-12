#include <cstdio>
#include <cmath>
int
c(int n,int d) {
  int md=pow(d,4),i=0;
  do {
    for(;n>=md;n-=md,i++);
    md/=d;
  } while(md>=1);
  return i;
}
int
main() {
  for(int i=1000;i<9999;i++)
    if(c(i,10)==c(i,12)&&c(i,12)==c(i,16))
      printf("%d\n",i);
}
