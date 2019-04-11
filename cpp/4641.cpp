#include <cstdio>
#include <cstring>
int i,t,arr[16],c[101],s;
int
main() {
  for(;;i=0,s=0,memset(c, 0, sizeof(int)*101)) {
    scanf("%d",arr);
    if(arr[0]==-1) {
      break;
    }
    for(i=0;arr[i++]!=0;) {
      scanf("%d",&arr[i]);
    }
    i--;
    for(int j=0;j<i;j++) {
      c[arr[j]]|=0x1;
      c[arr[j]*2]|=0x2;
    }
    for(int j=1;j<101;j++) {
      if(c[j]==0x3) {
        s++;
      }
    }
    printf("%d\n",s);
  }
}
