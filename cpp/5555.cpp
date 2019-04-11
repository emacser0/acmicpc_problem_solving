#include <cstdio>
#include <cstring>
int N,cnt;
char pattern[11],ring[11];
int
main() {
  scanf("%s%d",pattern,&N);
  int plen = strlen(pattern);
  for(int i=0;i<N;i++) {
    scanf("%s",ring);
    for(int i=0;i<10+plen-1;i++) {
      int cond=1;
      for(int j=0;j<plen;j++) {
        if(ring[(i+j)%10]!=pattern[j]) {
          cond=0;
          break;
        }
      }
      if(cond) {
        cnt++;
        break;
      }
    }
  }
  printf("%d\n",cnt);
}
