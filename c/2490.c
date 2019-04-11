#include <stdio.h>
int s,t;
char ret[3];

int
main() {  
  for(int i=0;i<3;i++) {
    for(int i=0;i<4;i++) {
      scanf("%d",&t);
      s+=t;	    
    }
    ret[i]=s==4?'E':'D'-s;
    s=0;
  }
  for(int i=0;i<3;i++) {
    printf("%c\n",ret[i]);
  }
}
