#include <cstdio>
#include <cstring>
char s[999],len,np;
int
main() {
  scanf("%s",s);
  len=strlen(s);
  for(int i=0;i<len;i++) {
    if(s[i]!=s[len-i-1]) {
      np=1;
      break;
    }
  }
  printf(np?"0":"1");
}
