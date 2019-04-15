#include <stdio.h>
int T,M,t;
char D[5],s[5];
int
main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%d%s",&M,&D);
    if(D[0]=='C') {
      for(int j=0;j<M;j++) {
        scanf("%s",s);
        printf("%d ",s[0]-'A'+1);
      }
      puts("");
    }
    else {
      for(int j=0;j<M;j++) {
        scanf("%d",&t);
        printf("%c ",'A'+t-1);
      }
      puts("");
    }
  }
}
