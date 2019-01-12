#include <cstdio>
#include <cstring>
int N,si,cnt;
char str[100004],stack[100004];
int
main() {
  scanf("%d",&N);
  for(int i=0;i<N;i++) {
    scanf("%s",str);
    int len=strlen(str);
    si=0;
    stack[si++]=str[0];
    for(int j=1;j<len;j++) {
      if((si!=0)&&(stack[si-1]==str[j])) {
        si--;
      }
      else {
        stack[si++]=str[j];
      }
    }
    cnt+=si?0:1;
  }
  printf("%d\n",cnt);
}
