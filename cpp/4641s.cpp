#include <cstdio>
#include <cstring>
int i,j,t,c[101],s;
int
main() {
  for(;;i=j=s=0,memset(c,0,4*101)) {
    for(;scanf("%d",&t);) {
      if(t<0)return 0;
      if(!t)break;
      c[t]|=1,c[t*2]|=2;
    }
    for(j=1;j<101;s+=c[j++]/3);
    printf("%d\n",s);
  }
}
