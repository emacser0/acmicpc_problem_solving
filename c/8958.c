#include <stdio.h>
#include <string.h>
int n,i,score[100],chain;
char buf[80];

int
main() {
  for(scanf("%d",&n);i<n;i++) {
    scanf("%s",buf);
    for(int j=0;j<strlen(buf);j++) {
      if(buf[j]=='O') {
        score[i]++;
        score[i]+=chain;
        chain++;
      }
      else {
        chain=0;
      }
    }
    chain=0;
  }
  for(int i=0;i<n;i++) {
    printf("%d\n",score[i]);
  }
}
