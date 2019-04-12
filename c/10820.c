#include <stdio.h>
#include <ctype.h>
char buf[108];
int a,b,c,d;
int
main() {
  while(fgets(buf,104,stdin)!=NULL) {
    a=b=c=d=0;
    if(buf[0]=='\n')break;
    for(int i=0;buf[i]!='\n'&&buf[i]!='\0';i++) {
      if(islower(buf[i]))a++;
      else if(isupper(buf[i]))b++;
      else if(isdigit(buf[i]))c++;
      else d++;
    }
    printf("%d %d %d %d\n",a,b,c,d);
  }
}
