#include <stdio.h>
#include <stdlib.h>
char s[20];
int n,m,f;
int
main() {
  scanf("%s%d",s,&m);
  n=atoi(s);
  for(int i=0;i<n;i++) {
    for(int j=0;s[j]!='\0';j++) {
      m--;
      putchar(s[j]);
      if(!m){
        f=1;
        break;
      }
    }
    if(f)break;
  }
  puts("");
}
