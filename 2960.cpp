#include <cstdio>
int n,k,i;
int d[1001];
int
main() {
  scanf("%d%d",&n,&k);
  for(;;) {
    for(i=2;i<=n;i++) {
      if(!d[i]) {
        break;
      }
    }
    for(int j=i;j<=n;j++) {
      if(j%i||d[j]) {
        continue;
      }
      d[j]=1;
      k--;
      if(k==0) {
        printf("%d\n",j);
        return 0;
      }
    }
  }
}
