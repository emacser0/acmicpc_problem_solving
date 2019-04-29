#include <stdio.h>
int n,t,cnt;
int main() {
  scanf("%d",&n);
  while(n/10) {
    t=n;
    n=1;
    while(t) {
      n*=t%10;
      t/=10;
    }
    cnt++;
  }
  printf("%d\n",cnt);
}
