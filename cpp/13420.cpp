#include <stdio.h>
long long T,a,b,c,r;
char op[5],t[15]="correct",f[15]="wrong answer";
int main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++,r=0) {
    scanf("%lld%s%lld%*s%lld",&a,op,&b,&c);
    switch(op[0]) {
      case '+':
      r=a+b==c;
      break;
      case '-':
      r=a-b==c;
      break;
      case '*':
      r=a*b==c;
      break;
      case '/':
      r=a/b==c;
      break;
    }
    puts(r?t:f);
  }
}
