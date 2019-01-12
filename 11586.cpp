#include <cstdio>
#include <cstring>
char mirror[104][104];
int
main() {
  int N,K;
  scanf("%d",&N);
  for(int i=0;i<N;i++) {
    scanf("%s",mirror[i]);
  }
  scanf("%d",&K);
  if(K==1) {
    for(int i=0;i<N;i++) {
      printf("%s\n",mirror[i]);
    }
  }
  else if(K==2) {
    for(int i=0;i<N;i++) {
      for(int j=N-1;j>=0;j--) {
        putchar(mirror[i][j]);
      }
      puts("");
    }
  }
  else {
    for(int i=N-1;i>=0;i--) {
      printf("%s\n",mirror[i]);
    }
  }
}
