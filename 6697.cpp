#include <cstdio>
#include <cmath>
int
c(int n,int notation) {
  int max_d=pow(notation,4),cnt=0;
  do {
    while(n>=max_d) {
      n-=max_d;
      cnt++;
    }
    max_d/=notation;
  } while(max_d>=1);
  return cnt;
}
int
main() {
  for(int i=1000;i<10000;i++) {
    if(c(i,10)==c(i,12)&&c(i,12)==c(i,16)) {
      printf("%d\n",i);
    }
  }
}
