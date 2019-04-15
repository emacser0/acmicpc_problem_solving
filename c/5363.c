#include <stdio.h>
#include <string.h>
char s[104],*p;
int n,b[100],bi;
int
main() {
  scanf("%d\n",&n);
  for(int i=0;i<n;i++) {
    fgets(s,100,stdin);
    s[strlen(s)-1]='\0';
    bi=0;
    b[bi++]=strtok(s," ")-s;
    while((p=strtok(NULL," "))!=NULL){
      b[bi++]=p-s;
    }
    for(int j=2;j<bi;j++) {
      printf("%s ",s+b[j]);
    }
    printf("%s %s\n",s+b[0],s+b[1]);
  }
}
