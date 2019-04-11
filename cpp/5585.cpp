#include <cstdio>
int n,m[6]={500,100,50,10,5,1},c;
int
main() {
  scanf("%d",&n);
  n=1000-n;
  for(int i=0;i<6;i++) {
    while(n>=m[i]) {
      n-=m[i];
      c++;
    }
  }
  printf("%d\n",c);
}
