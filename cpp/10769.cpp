#include <cstdio>
#include <cstring>
char str[256],happy[4]={":-)"},sad[4]={":-("};
int happycnt,sadcnt;
int
main() {
  fgets(str,255,stdin);
  int len = strlen(str);
  for(int i=0;i<len-2;i++) {
    int happycond=1,sadcond=1;
    for(int j=0;j<3;j++) {
      if(str[i+j]!=happy[j]) {
        happycond=0;
      }
      if(str[i+j]!=sad[j]) {
        sadcond=0;
      }
    }
    if(happycond) {
      happycnt++;
    }
    if(sadcond) {
      sadcnt++;
    }
  }
  if(happycnt==0&&sadcnt==0) {
    puts("none");
  }
  else if(happycnt==sadcnt){
    puts("unsure");
  }
  else if(happycnt>sadcnt) {
    puts("happy");
  }
  else {
    puts("sad");
  }
}
