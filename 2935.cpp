#include <cstdio>
#include <cstring>
char buf1[104],buf2[3],buf3[104];
int a,b,c;
int
main() {
  scanf("%s%s%s",buf1,buf2,buf3);
  a=strlen(buf1);
  b=buf2[0]=='+'?0:1;  
  c=strlen(buf3);
  if(b) {
    putchar('1');
    for(int i=0;i<(a-1)+(c-1);i++) {
      putchar('0');
    }
  }
  else {
    int maxl=a>c?a:c;
    for(int i=maxl;i>0;i--) {
      if(i==a||i==c) {        
        putchar(a==c?'2':'1');
      }
      else putchar('0');
    }
  }
  puts("");
}
