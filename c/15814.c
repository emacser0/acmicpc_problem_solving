#include <stdio.h>
#define swap(a,b) t=a;a=b;b=t
char s[104];
int n,a,b,t;
int
main() {
  scanf("%s\n%d",s,&n);
  for(int i=0;i<n;i++) {
    scanf("%d%d",&a,&b);
    swap(s[a],s[b]);
  }
  printf("%s\n",s);
}
