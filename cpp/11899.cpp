#include <stdio.h>
int x,c;
char ch;
int main() {
  while((ch=getchar())!='\n') {
    x=ch=='('?x+1:x-1;
    if(x<0) x++,c++;
  }
  printf("%d\n",c+x);
}
