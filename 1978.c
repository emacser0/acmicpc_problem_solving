#include <stdio.h>
int n,pc,c=1,i,j,buf[100];

int
main() {
  for(scanf("%d",&n);i<n;i++) {
    scanf("%d",&buf[i]);
    c=buf[i]==1?0:c;
    for(j=2;j<buf[i];j++) {
      if(buf[i]%j==0) {
        c=0;pc+=c;c=1;
      }
    }      
  }
  printf("%d\n",pc);
}
