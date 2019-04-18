#include <stdio.h>
#include <string.h>
int T,X,d[10],c;
int main() {
  scanf("%d",&T);
  for(int i=0;i<T;memset(d,0,sizeof(int)*10),c=0,i++) {
    scanf("%d",&X);
    while(X) {
      d[X%10]=1;
      X/=10;
    }
    for(int i=0;i<10;i++) {
      if(d[i])c++;
    }
    printf("%d\n",c);
  }
}
