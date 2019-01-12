#include <cstdio>
double e;
int fac(int n) {
  int r=1;
  if(n<2) return 1;
  for(int i=2;i<=n;i++) {
    r*=i;
  }
  return r;
}
int
main() {
  printf("n e\n- -----------\n");
  for(int i=0;i<10;i++) {
    for(int j=0;j<=i;j++) {
      e+=1.0/fac(j);
    }
    if(i>2) {
      printf("%d %.9f\n",i,e);
    }
    else if(i==2) {
      printf("%d %.1f\n",i,e);
    }
    else {
      printf("%d %d\n",i,(int)e);
    }
    e=0;
  }
}
