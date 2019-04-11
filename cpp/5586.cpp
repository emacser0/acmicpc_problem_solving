#include <cstdio>
#include <cstring>
char str[10000];
int joi,ioi;
int
main() {
  scanf("%s",str);
  int len = strlen(str);
  for(int i=0;i+2<len;i++) {
    if(str[i+1]=='O'&&str[i+2]=='I') {
      if(str[i]=='J') {
        joi++;
      }
      else if(str[i]=='I') {
        ioi++;
      }
    }
  }
  printf("%d\n%d\n",joi,ioi);
}
