#include <cstdio>
#include <memory.h>
int t,n,k;
int
main() {
  scanf("%d",&t);
  for(int i=0;i<t;i++) {
    scanf("%d%d",&k,&n);
    int p[14]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    for(int i=0;i<k;i++) {
      int np[14];
      for(int j=0;j<n;j++) {
        int sum=0;
        for(int x=0;x<=j;x++) {
          sum += p[x];
        }        
        np[j]=sum;
      }
      memcpy(p,np,sizeof(p));      
    }
    printf("%d\n",p[n-1]);
  }
}
