#include <stdio.h>
int n,m,si;
char s[1004],b[1004];
int
main() {
  scanf("%d%d%s",&n,&m,s);
  for(int i=0;i<m;i++,si=0) {
    scanf("%s",b);
    for(int j=0;b[j]!='\0';j++) {
      if(s[si]==b[j])si++;
    }
    printf("%s\n",si==n?"true":"false");
  }
}
