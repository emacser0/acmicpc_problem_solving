#include <stdio.h>
int i,c,n,b[1000];
float a,ap,b2[1000];

int
main() {
  for(scanf("%d",&c);i<c;i++) {
    scanf("%d",&n);
    for(int i=0;i<n;a+=b[i++]) {
      scanf("%d",&b[i]);
    }    
    a/=n;
    for(int i=0;i<n;i++) {
      ap=b[i]>a?ap+1:ap;
    }      
    b2[i]=ap/n*100;
    for(int i=0;i<n;i++)
      b[i]=0;a=ap=0;
  }
  for(int i=0;i<c;i++) {
    printf("%.3f%%\n",b2[i]);
  }    
}
