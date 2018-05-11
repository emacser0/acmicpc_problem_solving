#include <stdio.h>
#include <string.h>
int i,t,l;
char buf[101],buf2[11];

int
main() {  
  scanf("%s",buf);
  l=strlen(buf);
  for(;i<l;i++) {
    buf2[t]=buf[i];
    if(t==9&&i!=l-1) {
      puts(buf2);
    }
    else if(l<10) {
      puts(buf);
      break;
    }
    else if(i==l-1) {
      buf2[t+1]='\0';
      puts(buf2);
      break;
    }
    t=t==9?0:t+1;
  }
}
