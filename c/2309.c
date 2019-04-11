#include <stdio.h>
int i,j,k,n[9],c[100],s,t;

int
main() {
  for(;~scanf("%d",&n[i]);s+=n[i++]) {
    c[n[i]]++;
  }    
  for(i=0;i<100;i++) {
    for(;c[i];c[i]--) {
      n[t++]=i;
    }      
  }    
  for(i=0;i<8;i++) {
    for(j=i+1;j<9;j++) {
      if(s-n[i]-n[j]==100) {
        for(;k<9;k++) {
          if(k!=i&&k!=j) {
            printf("%d\n",n[k]);
          }
        }        
      }
    }
  }    
}
