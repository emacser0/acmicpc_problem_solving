#include <stdio.h>
int c,i,t,f;

int main() {
  for(;(c=getchar())!=-1&&c!=10;) {
    if((c==32)&&t==0&&f) {
      t=1;
    }
    if(c>=65&&c<300) {
      if(!f) {
        i++;
      }        
      f=1;
      if(t) {
        i++;
      }        
      t=0;
    }
  }
  printf("%d\n",i);
}
