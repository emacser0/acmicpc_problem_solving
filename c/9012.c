#include <stdio.h>
#include <string.h>
int t,c;
char buf[99];

int
main() {
  scanf("%d",&t);
  for(int i=0;i<t;i++) {
    scanf("%s",buf);
    for(int j=0;j<strlen(buf);j++) {
      if(c<0) {
        break;
      }
      if(buf[j]=='(') {
        c++;
      }
      else if(buf[j]==')') {
        c--;
      }
    }
    if(c==0) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }
    c=0;
  }
}
