#include <cstdio>
#include <cstring>
char buf[50],v[5]={'a','e','i','o','u'},ve,vc,cc,na;
int
isv(char ch) {
  for(int i=0;i<5;i++)
    if(ch==v[i])
      return 1;
  return 0;
}
int
main() {
  for(;~scanf("%s",buf);ve=vc=cc=na=0) {
    if(!strcmp(buf,"end")) break;
    for(int i=0;buf[i]!='\0';i++) {
      if(isv(buf[i]))
        ve=1,cc=0,vc++;
      else
        vc=0,cc++;
      if(vc==3||cc==3||(i>0&&(buf[i]!='e'&&buf[i]!='o'&&buf[i-1]==buf[i]))) {
        na=1;
        break;
      }
    }
    if(!ve)na=1;
    printf("<%s> is%s acceptable.\n",buf,na?" not":"");
  }
}
