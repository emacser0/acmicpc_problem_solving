#include <cstdio>
#include <cstring>
char name[11],fbi;
int
main() {
  for(int i=0;i<5;i++) {
    scanf("%s",name);
    int len = strlen(name);
    for(int j=0;j+2<len;j++) {
      if(name[j]=='F'&&name[j+1]=='B'&&name[j+2]=='I') {
        fbi=1;
        printf("%d ",i+1);
        break;
      }
    }
  }
  if(!fbi) {
    printf("HE GOT AWAY!");
  }
  puts("");
}
