#include <cstdio>
#define swap(a,b) {int t=a;a=b;b=t;}
int n[3],t;
char buf[4];
int
main() {
  scanf("%d%d%d%s",n,n+1,n+2,buf);
  if(n[0]>n[1]) swap(n[0],n[1]);
  if(n[1]>n[2]) swap(n[1],n[2]);
  if(n[0]>n[1]) swap(n[0],n[1]);
  for(int i=0;i<3;i++) {
    printf("%d ",n[buf[i]-'A']);
  }
  puts("");
}
