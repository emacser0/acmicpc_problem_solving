#include <cstdio>
#include <cstring>
int M,N,ai,bi;
char a[31],b[31];
int
main() {
  scanf("%s%s",a,b);
  int N=strlen(a),M=strlen(b);
  for(int i=0;i<N;i++) {
    int cond=0;
    for(int j=0;j<M;j++) {
      if(a[i]==b[j]) {
        cond=1;
        ai=i,bi=j;
        break;
      }
    }
    if(cond) {
      break;
    }
  }
  for(int i=0;i<M;i++) {
    if(i==bi) {
      printf("%s\n",a);
    }
    else {
      for(int j=0;j<N;j++) {
        if(j==ai) {
          putchar(b[i]);
        }
        else {
          putchar('.');
        }
      }
      puts("");
    }
  }
}
