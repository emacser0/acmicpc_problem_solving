#include <stdio.h>
int T,N;
char s[99];
int main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%d%s",&N,s);
    for(int j=0;s[j]!='\0';j++) {
      if(j!=N-1)putchar(s[j]);
    }
    puts("");
  }
}
