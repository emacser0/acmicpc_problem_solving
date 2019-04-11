#include <stdio.h>
int t[1000001];
int x;

int
recto1(int x,int end) {
  t[x]=x;
  if(x<2||end<2||x>end)
    return 0;
  if(x==2) {
    t[2]=1;
  }    
  else {
    t[x]=x%3==0?t[x/3]+1:t[x];
    t[x]=x%2==0?t[x]<t[x/2]+1?t[x]:t[x/2]+1:t[x];
    t[x]=t[x]<t[x-1]+1?t[x]:t[x-1]+1;
  }
  if(x==end) {
    return t[x];
  }
  else {
    return recto1(x+1,end);
  }
}

int
main() {
  scanf("%d",&x);
  printf("%d\n",recto1(2,x));
}
