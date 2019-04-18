#include <stdio.h>
#include <string.h>
#include <ctype.h>
char n[20];
int b,r,l,m=1;
int
main() {
  scanf("%s %d",n,&b);
  l=strlen(n)-1;
  for(int i=l;i>=0;i--,m*=b) {
    if(isalpha(n[i]))r+=((int)n[i]-'A'+10)*m;
    else r+=((int)n[i]-'0')*m;
  }
  printf("%d\n",r);
}
