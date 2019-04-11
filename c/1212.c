#include <stdio.h>
#include <string.h>

void
print_ob(char *buf) {
  int len=strlen(buf),cur,s=0;
  char pbuf[3];
  if(len==1&&buf[0]=='0') {
    printf("0\n");
    return;
  }
  for(int i=0;i<len;i++) {
    cur=buf[i]-'0';
    for(int j=2;j>=0;j--) {
      pbuf[j]=cur%2+'0';
      cur/=2;
    }
    if(i==0) {
      for(int i=0;i<3;i++) {
        if(pbuf[i]=='0') {
          s++;
        }
        else {
          break;
        }
      }
      printf("%s",&pbuf[s]);
    }
    else {
      printf("%s",pbuf);
    }	
  }
  printf("\n");
}

int
main() {
  char buf[333354];
  scanf("%s",buf);
  print_ob(buf);
}
