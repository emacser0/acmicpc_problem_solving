#include <cstdio>
#include <cstring>
char table[8][4] = {"c=","c-","dz=","d-","lj","nj","s=","z="},str[101],matched[101];
int len,i,cnt;
int
main() {
  scanf("%s",str);
  len = strlen(str);
  for(int i=0;i<8;i++) {
    int plen = strlen(table[i]);
    for(int j=0;j<len;j++) {
      int cond=1;
      if(strlen(&str[j])<plen) {
        break;
      }
      for(int k=0;k<plen;k++) {
        if(str[j+k]!=table[i][k]||matched[j+k]) {
          cond=0;
        }
      }
      if(cond) {
        for(int k=0;k<plen;k++) {
          matched[j+k]=1;
        }
        cnt++;
      }
    }
  }
  for(int i=0;i<len;i++) {
    if(!matched[i]) {
      cnt++;
    }
  }
  printf("%d\n",cnt);
}
