#include <cstdio>
int n;
char buf[51];
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%s",buf);
    for(int i=0;buf[i]!='\0';i++) {
      buf[i]=buf[i]=='Z'?'A':buf[i]+1;
    }
    printf("String #%d\n%s\n\n",i+1,buf);
  }
}
