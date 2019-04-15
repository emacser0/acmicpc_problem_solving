#include <stdio.h>
char buf[104][20];
#define tswap() {t=r,ti=i;}
#define dswap() {d=r,di=i;}
int n,a,b,c,r,t,ti,d=2e9,di;
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%s%d%d%d",buf[i],&a,&b,&c);
    r=c*1e5+b*1e3+a;
    if(r>t) tswap()
    if(r<d) dswap()
  }
  printf("%s\n%s\n",buf[ti],buf[di]);
}
